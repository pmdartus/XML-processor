#ifndef ITEM_H
#define ITEM_H

class tag;

class Item 
{

private:
	Item* parent;
	
public:
    Item();
    ~Item();
    const Item* getParent() const;
};

#endif
