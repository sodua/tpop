public class TestBusinessClass{
    public static void main(String [] args){
        //Implements the restarant class for Moes Restaurant.
        double moes_week1;
        double moes_week2;
        Restaurant moesRestaurant = new Restaurant(1);
        moesRestaurant.setFoodReceipt(14000);
        moesRestaurant.setDrinkReceipt(9000);
        moes_week1 = moesRestaurant.calculateTax();
        System.out.println("Week 1: " + moesRestaurant.print(moes_week1));
        moesRestaurant.setFoodReceipt(12500);
        moesRestaurant.setDrinkReceipt(12500);
        moes_week2 = moesRestaurant.calculateTax();
        System.out.println("Week 2: " + moesRestaurant.print(moes_week2));
        
        //Implements the Restaurant class for Joes Restaurant.
        double joes_week1;
        double joes_week2;
        Restaurant joesRestaurant = new Restaurant(2, 4000, 3500);
        joes_week1 = joesRestaurant.calculateTax();
        System.out.println("Week 1: " + joesRestaurant.print(joes_week1));
        joesRestaurant.setFoodReceipt(2500);
        joesRestaurant.setDrinkReceipt(3500);
        joes_week2 = joesRestaurant.calculateTax();
        System.out.println("Week 2: " + joesRestaurant.print(joes_week2));
        
        //Implements the ConvenientStore subclass for six12 convenient store.
        double six12_week1;
        double six12_week2;
        ConvenientStore six12 = new ConvenientStore(612,6000,2400);
        six12_week1 = six12.calculateTax();
        System.out.println("Week 1: " + six12.print(six12_week1));
        six12.setOtherReceipts(5927);
        six12.setNewsReceipts(1700);
        six12_week2 = six12.calculateTax();
        System.out.println("Week 2: " + six12.print(six12_week2));
        
        double ritz_week1;
        double ritz_week2;
        Hotel ritz = new Hotel(3,25000, .98);
        ritz_week1 = ritz.calculateTax();
        System.out.println("Week 1: " + ritz.print(ritz_week1));
        ritz.setReceipts(21500);
        ritz.setOccupancy(.88);
        ritz_week2 = ritz.calculateTax();
        System.out.println("Week 2: " + ritz.print(ritz_week2));
        
        double notel_week1;
        double notel_week2;
        Hotel notel = new Hotel(4,5500, .93);
        notel_week1 = notel.calculateTax();
        System.out.println("Week 1: " + notel.print(notel_week1));
        notel.setReceipts(6575);
        notel.setOccupancy(.98);
        notel_week2 = notel.calculateTax();
        System.out.println("Week 2: " + notel.print(notel_week2));
        
        
        
    }
}
