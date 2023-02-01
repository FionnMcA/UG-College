public class Item
{
    private String name;
    private int price;
    private long itemId;
    
    public Item(String itemName, long id) //item constructor
    {
        name = itemName;
        itemId = id;
        this.price = price;
    }
    
    public void setPrice(int price) //a method that lets the user set the price of an item by inputting it.
    {
        this.price = price;    
    }
    
    public int getPrice()
    {
        return price;
    }
    
    public String getName() {
        return name;
    }
    
    @Override
    public String toString() //to String method
    {
        String out = "Item Id: " + itemId + "\t" + name + "\tPrice: " + price;
        return out;
    }
    

}
