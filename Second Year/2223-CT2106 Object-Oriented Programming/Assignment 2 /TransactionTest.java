
public class TransactionTest
{
    
    public static void main(String[] args)
    {
        System.out.println("\n\n\n\n\n");
        TransactionTest test = new TransactionTest();
        System.out.println("~~~~~~~~~~Transaction 1~~~~~~~~~~");
        test.transaction1();
        System.out.println("\n~~~~~~~~~~Transaction 2~~~~~~~~~~");
        test.transaction2();
    }
    
    public void transaction1(){
        Customer customer = new Customer("Niamh", "O'Leary", "niamhol@zmail.com");
        ShoppingCart cart = new ShoppingCart(customer);
        
        Item item1 = new Item("Is This it", 135);
        item1.setPrice(60);
        cart.add(item1);
        Item item2 = new Item("Room On Fire", 136);
        item2.setPrice(45);
        cart.add(item2);
        Item item3 = new Item("First Impressions of Earth", 137);
        item3.setPrice(40);
        cart.add(item3);
    
        cart.close();
        
        Item item4 = new Item("Angles", 138); //testing adding an item to the cart when the cart is closed
        item4.setPrice(30);
        cart.add(item4);
        
        cart.printItems();
        System.out.println("There are " + cart.getTotal() + " items in your cart");
        
        Address billing = new Address("First Street", "New York", "H91 QF5G", "America");
        Address delivery = new Address("Second Street", "New York", "H91 QF5G", "America");
        
        Order order = new Order(customer, cart, cart.getItems(), billing, delivery);      
        Email email = new Email(order);
        Payment payment = new Payment(order, "visa", 1748589346, "02/25", "revolut");
        
        payment.isPaymentValid();
        if(payment.getIsPaymentValid() == true){
            email.successfulEmail();
        }
        else{
            email.unsuccessfulEmail();
        }
    
    
    
    
        
        
        
        
    }
    
    public void transaction2(){
        Customer customer = new Customer("Julian", "Casablancas", "Jcas@Strokes.com");
        ShoppingCart cart = new ShoppingCart(customer);
        
        Item item1 = new Item("Angles", 138);
        item1.setPrice(30);
        cart.add(item1);
        
        Item item2 = new Item("Comedown Machine", 139);
        item2.setPrice(50);
        cart.add(item2);
        
        Item item3 = new Item("The New Abnormal",140);
        item3.setPrice(80);
        cart.add(item3);
        cart.printItems();
        System.out.println("There are " + cart.getTotal() + " items in your cart");
        cart.remove(1);
        cart.close();
        
        
        Address billing = new Address("Third Street", "Upstate New York", "H91 QF5G", "America");
        Address delivery = new Address("Third Street", "Upstate New York", "H91 QF5G", "America");
        
        Order order = new Order(customer, cart, cart.getItems(), billing, delivery);      
        

        Email email = new Email(order);
        Payment payment = new Payment(order, "Wiza", 1748589340, "02/25", "revolut");
        
        payment.isPaymentValid();
        if(payment.getIsPaymentValid() == true){
        email.successfulEmail();
    }
    else{
        email.unsuccessfulEmail();
    } 
    }
}
