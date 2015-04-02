#include <tools/XMLtools.h>
#include <controller/MasterClass.h>
#include <controller/EventGame.h>
#include <controller/EventEnemy.h>


/* CONVERSION VERS STRING */
template <typename T> string toString(const T& t) { 
    ostringstream os; 
    os<<t; 
    return os.str(); 
} 



/* CONSTRUIT UN FICHIER XML A PARTIR DES DONNÉES SAISIES */
bool buildSpriteMap(string filename, vector<Int2> anim, vector<Int2> pos, vector<Int2> size)
{
    if(pos.size()!=size.size() || pos.size()<=0)
        return false;

    ofstream file(filename.c_str(), ios::out | ios::trunc);

    if(!file)
        return false;


    xml_document<> doc;

    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* global = doc.allocate_node(node_element, "document");
    doc.append_node(global);


    for(unsigned int nb=0; nb<anim.size(); ++nb)
    {
        xml_node<> *animation = doc.allocate_node(node_element, "animation");
        char* nb_c = doc.allocate_string(toString(nb).c_str());
        animation->append_attribute(doc.allocate_attribute("num",nb_c));
        global->append_node(animation);

        for(int i=anim[nb].x; i<=anim[nb].y; ++i)
        {
            xml_node<> *sprite = doc.allocate_node(node_element, "sprite");
            char* i_c = doc.allocate_string(toString(i).c_str());
            sprite->append_attribute(doc.allocate_attribute("num",i_c));
            animation->append_node(sprite);

            xml_node<> *p = doc.allocate_node(node_element, "position");
            char* x = doc.allocate_string(toString(pos[i].x).c_str());
            char* y = doc.allocate_string(toString(pos[i].y).c_str());
            p->append_attribute(doc.allocate_attribute("x",x));
            p->append_attribute(doc.allocate_attribute("y",y));
            sprite->append_node(p);

            xml_node<> *s = doc.allocate_node(node_element, "size");
            char* w = doc.allocate_string(toString(size[i].x).c_str());
            char* h = doc.allocate_string(toString(size[i].y).c_str());
            s->append_attribute(doc.allocate_attribute("w",w));
            s->append_attribute(doc.allocate_attribute("h",h));
            sprite->append_node(s);
        }
    }

    file << doc; 

    return true; 
}










/* CHARGE UN FICHIER XML DE DESCRIPTION DES SPRITES */
bool loadSpriteMap(string filename, vector<Int2>* v_anim, vector<int>* v_speed, vector<Int2>* v_pos, vector<Int2>* v_size)
{
    xml_document<> doc;

    ifstream file(filename.c_str());

    if(!file)
        return false;

    stringstream buffer;
    buffer << file.rdbuf();
    string content(buffer.str());

    file.close();
   
    doc.parse<0>(&content[0]);

    xml_node<> *document = doc.first_node();

    for(xml_node<> *animation=document->first_node("animation"); animation; animation=animation->next_sibling())
    {
        Int2 anim(v_pos->size(),0);

        xml_attribute<> *sAttr;
        if((sAttr = animation->first_attribute("speed")))
            v_speed->push_back(atoi(sAttr->value()));
        else
            v_speed->push_back(-1);

        for(xml_node<> *sprite=animation->first_node("sprite"); sprite; sprite=sprite->next_sibling())
        {
            xml_attribute<> *xAttr = sprite->first_attribute("x");
            xml_attribute<> *yAttr = sprite->first_attribute("y");
            v_pos->push_back(Int2(atoi(xAttr->value()),atoi(yAttr->value())));

            xml_attribute<> *wAttr = sprite->first_attribute("w");
            xml_attribute<> *hAttr = sprite->first_attribute("h");
            v_size->push_back(Int2(atoi(wAttr->value()),atoi(hAttr->value())));
        }

        anim.y = v_pos->size()-1;
        v_anim->push_back(anim);
    }
    
    return true;
}













bool loadLevelXML(string filename, Config* conf, Environment* env, list<EventGame*>* evts, vector<Texture*>* tex)
{   
    xml_document<> doc;

    /* CHARGEMENT FICHIER */
    ifstream file(filename.c_str());

    if(!file)
        return false;


    /* INITIALISATION */
    stringstream buffer;
    buffer << file.rdbuf();
    string content(buffer.str());

    file.close();
   
    doc.parse<0>(&content[0]);


    /* NOEUX PRINCIPAUX */
    xml_node<> *document    = doc.first_node();
    xml_node<> *level       = document->first_node("level");
    xml_node<> *environment = level->first_node("environment");
    xml_node<> *decors      = environment->first_node("decors");
    xml_node<> *platforms   = environment->first_node("platforms");
    xml_node<> *events      = level->first_node("events");


    /* DECORS */
    for(xml_node<> *decor=decors->first_node("decor"); decor; decor=decor->next_sibling())
    {
        // déclaration
        int tmp_z;
        string tmp_file;
        Texture* tmp_tex;

        // récupération des données
        xml_attribute<> *zAttr = decor->first_attribute("z");
        tmp_z = atoi(zAttr->value());
        tmp_file = decor->value();

        // construction texture
        tmp_tex = new Texture();
        tmp_tex->loadFromFile("res/tex/decor/"+tmp_file);
        tmp_tex->setRepeated(true);
        tex->push_back(tmp_tex);

        // construction de l'objet
        env->addDecor(conf->resolution,tmp_tex,tmp_z);
    }


    /* PLATFORMS */
    for(xml_node<> *platform=platforms->first_node("platform"); platform; platform=platform->next_sibling())
    {
        // déclaration
        Int2 tmp_pos;
        Int2 tmp_siz;
        string tmp_file = "";
        bool visible = true;
        Texture* tmp_tex;

        // récupération des données
        xml_node<> *position = platform->first_node("position");
        xml_attribute<> *xAttr = position->first_attribute("x");
        xml_attribute<> *yAttr = position->first_attribute("y");
        tmp_pos = Int2(atoi(xAttr->value()),atoi(yAttr->value()));
        xml_node<> *size = platform->first_node("size");
        xml_attribute<> *wAttr = size->first_attribute("w");
        xml_attribute<> *hAttr = size->first_attribute("h");
        tmp_siz = Int2(atoi(wAttr->value()),atoi(hAttr->value()));
        xml_attribute<> *visibleAttr;
        if((visibleAttr = platform->first_attribute("visible")))
            visible = atoi(visibleAttr->value());
        xml_node<> *sprite;
        if((sprite=platform->first_node("sprite")))
            tmp_file = sprite->value();

        // construction texture
        if(!tmp_file.empty())
        {
            tmp_tex = new Texture();
            tmp_tex->loadFromFile("res/tex/platform/"+tmp_file);
            tmp_tex->setRepeated(true);
            tex->push_back(tmp_tex);
        }
        else
            tmp_tex = NULL;

        // construction de l'objet
        env->addPlatform(tmp_pos,tmp_siz,0,visible,tmp_tex);
    }


    /* EVENEMENTS */
    for(xml_node<> *event=events->first_node("event"); event; event=event->next_sibling())
    {
        // déclaration
        string type;
        int pos;

         // récupération des données et construction
        type = event->first_attribute("type")->value();
        pos = atoi(event->first_attribute("pos")->value());

        if(type == "enemy")
        {
            Int2 tmp_pos(
                atoi(event->first_attribute("x")->value()),
                atoi(event->first_attribute("y")->value())
            );

            string type_e = event->first_attribute("enemy_type")->value();

            if(type_e == "REBEL")
                evts->push_back(new EventEnemy(pos, tmp_pos, Enemy::REBEL));
        }
    }

    
    return true;
}