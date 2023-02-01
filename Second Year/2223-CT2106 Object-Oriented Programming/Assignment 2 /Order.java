import java.util.Random;
import java.util.ArrayList;

public class Order
{
    private Customer customer;
    private ShoppingCart cart;
    private Address billing;
    private Address delivery;
    private long orderID;
    private ArrayList<Item> items;
    
    public Order(Customer customer, ShoppingCart cart, ArrayList<Item> items, Address billing, Address delivery) //constructor an order has a customer,
    //shopping cart, a list of the items, a billing address and a delivery address 
    {
        this.customer = customer;
        this.cart = cart;
        this.orderID = makeOrderID();
        this.items = new ArrayList<Item>(items); //make a new arrayList items.
        this.items = (ArrayList<Item>) cart.getItems().clone(); //copy the items from the cart into the new arrayList
        cart.getItems().clear();//remove all the items from the cart
        this.billing = billing;
        this.delivery = delivery;    
    }
    
    public void printOrder(){
        for (Item item : items) {
            System.out.println(item.toString()); //prints the toString from the item class
        }
    }
      
    public long makeOrderID(){ //makes a random orderID 
        Random random = new Random();
        return (long) random.nextInt(1000000000);
    }
    
    //getters
    public ArrayList<Item> getOrderItems(){
        return items;
    }
    
    public Customer getCustomer(){
        return customer;
    }
    
    public Address getBilling(){
        return billing;
    }
    
    public Address getDelivery(){
        return delivery;
    }
    
    public long getOrderID(){
        return orderID;
    }
}
