#ifndef ITEM_H
#define ITEM_H

class tag;

class Item 
{

private:
	
public:
	Item* parent = 0;
    
    const Item * getParent() const;
    void setParent(Item *parent);
    
};

#endif
