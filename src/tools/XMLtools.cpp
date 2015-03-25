#include <tools/XMLtools.h>


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
bool loadSpriteMap(string filename, vector<Int2>* v_anim, vector<Int2>* v_pos, vector<Int2>* v_size)
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

        for(xml_node<> *sprite=animation->first_node("sprite"); sprite; sprite=sprite->next_sibling())
        {
            xml_node<> *position = sprite->first_node("position");
            xml_attribute<> *xAttr = position->first_attribute("x");
            xml_attribute<> *yAttr = position->first_attribute("y");
            v_pos->push_back(Int2(atoi(xAttr->value()),atoi(yAttr->value())));

            xml_node<> *size = sprite->first_node("size");
            xml_attribute<> *wAttr = size->first_attribute("w");
            xml_attribute<> *hAttr = size->first_attribute("h");
            v_size->push_back(Int2(atoi(wAttr->value()),atoi(hAttr->value())));
        }

        anim.y = v_pos->size()-1;
        v_anim->push_back(anim);
    }
    
    return true;
}
