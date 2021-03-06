public abstract class Business
{
    private int account_number;
    private double receipts_amount, taxes_due;
   
    protected Business()
    {
    }
    protected Business(int accountParameter)
    {
        account_number = accountParameter;
    }
    public Business(int accountParameter, double receiptParameter)
    {
        account_number = accountParameter;
        receipts_amount = receiptParameter;
    }   
    public String print()
    {
        return ("The business number is " + account_number);
    }
}

//Hotel subclass of the Business class.

class Hotel extends Business 
{
    private int account_number;
    private double receipts_amount, occupancy_rate, high_occ_tax;
    private double receipts_tax, total_tax_due;
    
    public Hotel(int accountParameter)
    {
        account_number = accountParameter;
    }
    public Hotel(int accountParameter, double receiptsParameter, double occRateParameter)
    {
        account_number = accountParameter;
        receipts_amount = receiptsParameter;
        occupancy_rate = occRateParameter;
    }
    public void setReceipts(double receiptsParameter)
    {
        receipts_amount = receiptsParameter;
    }
    public double getReceipts()
    {
        return receipts_amount;
    }
    public void setOccupancy(double occRateParameter)
    {
        occupancy_rate = occRateParameter;
    }
    public double getOccupancy()
    {
        return occupancy_rate;
    }
    public double calculateTax()
    {
        if (occupancy_rate > .9)
        {
            high_occ_tax = .02 * receipts_amount;
        }
        else
        {
            high_occ_tax = 0;
        }
        receipts_tax = .06 * receipts_amount;
        total_tax_due = high_occ_tax + receipts_tax;
        return total_tax_due;
    }
    
    public String print(double taxParameter)
    {
        return ("The hotel number is " + account_number + ", total receipts are " + receipts_amount + ", and taxes due " 
                + taxParameter + ".");
    }
    
}

//Restaurant subclass of the Business class.

class Restaurant extends Business
{
    private int account_number;
    private double bar_tax, food_tax, drink_tax, tax_due, food_receipt, drink_receipt, total_due;
   
    public Restaurant(int accountParameter)
    {
        account_number = accountParameter;
    }
    public Restaurant(int accountParameter, double foodRecParameter, double drinkRecParameter)
    {
        account_number = accountParameter;
        drink_receipt = drinkRecParameter;
        food_receipt = foodRecParameter;
    }
    public void setFoodReceipt(double foodRecParameter)
    {
        food_receipt = foodRecParameter;
    }
    public void setDrinkReceipt(double drinkRecParameter) 
    {
        drink_receipt = drinkRecParameter;
    }
    public double getFoodReceipt()
    {
        return food_receipt;
    }
    public double getDrinkReceipt()
    {
        return drink_receipt;
    }
    public double calculateTax()
    {
        if (food_receipt < drink_receipt)
        {
            bar_tax = .03 * (drink_receipt + food_receipt);
        }
        else
        {
            bar_tax = 0;
        }
        drink_tax = .08 * drink_receipt;
        tax_due = bar_tax + drink_tax;
        return tax_due;
    }
    public String print(double taxParameter)
    {
        return ("The restaurant number is " + account_number + ", food receipts are "
                +  food_receipt + ", and drink receipts are " + drink_receipt + ". The total tax is " + taxParameter);
    }
}


//ConvenientStore subclass of the Business class parent class.

class ConvenientStore extends Business
{
    private int account_number;
    private double other_receipts, newspaper_receipts,tax_due;
    public ConvenientStore(int accountParameter)
    {
        account_number = accountParameter;
    }
    public ConvenientStore(int accountParameter, double otherParameter,double newsParameter)
    {
        account_number = accountParameter;
        other_receipts = otherParameter;
        newspaper_receipts = newsParameter;
        
    }
    public void setOtherReceipts(double otherParameter)
    {
        other_receipts = otherParameter;
    }
    public void setNewsReceipts(double newsParameter)
    {
        newspaper_receipts = newsParameter;
    }
    public double getOtherReceipts()
    {
        return other_receipts;
    }
    public double getNewsReceipts()
    {
        return newspaper_receipts;
    }
    public double calculateTax()
    {
        tax_due = .07 * other_receipts;
        return tax_due;
    }
    public String print(double taxParameter)
    {
        return ("The account number is " + account_number + ", newspaper receipts " + newspaper_receipts +
                    ", other receipts " + other_receipts + ". The tax due is " + taxParameter);
        
    }
}
