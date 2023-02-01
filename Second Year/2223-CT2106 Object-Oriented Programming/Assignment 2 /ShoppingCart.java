//import arrayList and random utility
import java.util.ArrayList;
import java.util.Random; 

public class ShoppingCart
{
    private Customer customer; 
    private Item item;
    private long cartId;
    private String time;
    private ArrayList<Item> items; 
    private int total;
    private boolean close = false; 
    
    
    public ShoppingCart(Customer customer) //shopping cart constructor and the shopping cart has a customer
    {
       this.total = total;
       this.cartId = makeCartId();
       this.customer = customer;
       items = new ArrayList<>(); //Initialise a  new empty array list for holding item objects
    }
    
    
    public long getCartId(){
        return cartId;
    }
    public long makeCartId(){ //makes a random number for the cartID
        Random random = new Random();
        return (long) random.nextInt(1000000000);
    }
    public void add(Item item){//reads in an item and adds it to the cart if its open.
        if(close == false){ //if the cart is open print what you've added
            items.add(item);
            System.out.println("You added: " + item.getName() + " to your cart (id "  + getCartId() + ")");
            //items.add(item); //adding the item to the arrayList items
        }
        else { //if the cart is closed print that its closed
            System.out.println("Sorry you cannot add " + item.getName() + " beacuse the shopping cart is closed");
        }
    }
    public void remove(int x){ //pass in the item index
        if(close == false){ //if the cart is open
        System.out.println("You removed: " + items.get(x).getName() + " from your cart (id "  + getCartId() + ")");
        items.remove(x);//you can remove the item of the index entered
        }
        else{
            System.out.println("Sorry you cannot add " + items.get(x).getName() + " beacuse the shopping cart is closed"); //the cart is closed so you cant remove an item
        }
    }
    public void printItems(){
        System.out.println("In your cart (id "  + getCartId() + ") there is");
        for(int i = 0; i < items.size(); i++){
            System.out.println(items.get(i));//prints the toString() of each item,
        }
    }
    
    public void close(){ //when called it sets the close to true which closes the cart
        System.out.println("You have closed the shopping cart");
        close = true;
    }
    
    
    public void clear(){ //when called it clears all the items out of the cart
        items.clear();
    }    
    
    public int getTotal(){
        return items.size(); //the size of the array 
    }
    
    public ArrayList<Item> getItems(){
        return items;
    }
    
    public Customer getCustomer(){
        return this.customer;
    }
    
}
