
public class Payment
{
    private Order order;
    private String creditCardType;
    private long cardNumber;
    private String date;
    private String bankName;
    private boolean isPaymentValid;
    
    
    public Payment(Order order, String creditCardType, long cardNumber,String date, String bankName)//constructor and a payment has an order
    {
        this.order = order;
        this.creditCardType = creditCardType;
        this.cardNumber = cardNumber;
        this.date = date;
        this.bankName = bankName;   
    }
    
    public void isPaymentValid(){ //method to check if the card is valid
        if(creditCardType.toLowerCase().equals("visa") || creditCardType.toLowerCase().equals("mastercard") && String.valueOf(cardNumber).length() == 10){ //checks if the card is either visa or mastercard and if the card number has 10 digits
            isPaymentValid = true;
        }
        
        
        else{
            isPaymentValid = false; //if its neither of the above it returns false because the payment isn't valid
        }
        
  
    }
    
    //getters
    public boolean getIsPaymentValid(){
        return isPaymentValid;
    }
    
    public String getCreditCardType(){
        return creditCardType;
    }
    
    public long getCardNumber(){
        return cardNumber;
    }

    public String getDate(){
        return date;
    }
    
    public String getBankName(){
        return bankName;
    }
}
