
/**
 * Description: This program calculates circumference, acceleration and factorial.
 *
 * Name: Sanil Srivastava
 * Date: 
 */
//To be able to use scanner for input
import java.util.Scanner;
public class Sanil_Assignment4_MathCalculator
{
    public static void main(String[] args)
    {
        //Brings in random number generator to be used
        Scanner input =new Scanner(System.in);
        
        // String holding either circumference, acceleration or factorial
        String stroption;
        //Boolean variable controlling loop that force the input to be either circumference, acceleration or factorial 
        boolean boolTryCatch = false ;
        //Boolean variable controlling try and catch in a loop
        boolean boolTryCatch2 = false ;
        //Boolean variable controlling try and catch in a loop
        boolean boolTryCatch3 = false ;
        //Boolean variable controlling try and catch in a loop
        boolean boolTryCatch4 = false ;
        //Boolean variable controlling try and catch in a loop
        boolean boolTryCatch5 = false ;
        //Boolean variable controlling try and catch in a loop
        boolean boolTryCatch6 = false ;
        //Boolean variable controlling the loop that loops the entire program
        boolean boolTryCatch7 = false ;
        //Boolean variable that controls yes or no input
        boolean boolTryCatch8 = false ;
        // Double variable holding the radius of the circle
        double dblradius = 0;
        //Double variable holding the circumference of the circle
        double dblcircumference;
        //Float variable holding the final velocity 
        float fltvelocityF = 0;
        //Float variable holding the initial velocity
        float fltvelocityI = 0;
        //Float variable holding the time it took
        float flttime = 0;
        //Int variable holding the factorial number
        int intnum = 0;
        //Int variable holding the answer for the factorial
        int intanswer = 0;
        //String variable holding yes or no which controls whether the loop will reoeat
        String stryesorno;
        
        //Clears terminal
        System.out.println('\u000C');
        
        
        
    //While loop that loops the entire program
    do 
    {
        //Outputs this the following to the user
        System.out.println("This program gives the option to calculate circumference, acceleration and factorial");
        
        
        do
        {
            //Outputs this the following to the user
            System.out.println("Please enter what you would like to calculate ");
            //Stores users input in stroption variable
            stroption = new Scanner(System.in).next().toLowerCase();
            
        //If statement that runs the specific sections of program based on users input
        //If user inputs circumference the following program runs
        if (stroption.equals("circumference"))
        {
            
            // While loop that loops if user enter invalid input
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please enter the radius of the circle");
                    //Stores users answer in dblradius variable
                    dblradius = new Scanner(System.in).nextDouble();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch2 = true;
                }
            }
            //boolTryCatch2 is the boolean variable controlling the loop
            while(boolTryCatch2);
            
            //calls method and sends variable to method then stores return in dblcircumference variable
            dblcircumference = circumference(dblradius);
            //Outputs this the following to the user
            System.out.printf("The circumference is %.4f ",dblcircumference);
            //Causes loop to end
            boolTryCatch = false;
        }
        //If users inputs acceleration the following section of program runs
        else if (stroption.equals("acceleration"))
        {
            
            //While loop that repeats if user enters invalid input
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please enter the final velocity in m/s");
                    //Stores users answer in fltvelocityf variable
                    fltvelocityF = new Scanner(System.in).nextFloat();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch3 = true;
                }
            }
            //boolTryCatch3 is the boolean variable controlling the loop
            while(boolTryCatch3);
            
            //While loop that repeats if user enters invalid input
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please enter the initial velocity in m/s");
                    //Stores users answer in fltvelocityI variable
                    fltvelocityI = new Scanner(System.in).nextFloat();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch4 = true;
                }
            }
            //boolTryCatch4 is the boolean variable controlling the loop
            while(boolTryCatch4);
            
            //While loop that repeats if user enters invalid input
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please enter the time it took in seconds");
                    //Stores users answer in flttime variable
                    flttime = new Scanner(System.in).nextFloat();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch5 = true;
                }
                
                
            }
            //boolTryCatch5 is the boolean variable controlling the loop
            while(boolTryCatch5);
            
            //calls method and sends variables to the method
            acceleration(fltvelocityF, fltvelocityI, flttime);
            
            //ends loop
            boolTryCatch = false;
        }
        //If user inputs factorial the following section of program runs
        else if(stroption.equals("factorial"))
        {
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please enter the integer number you want to calculate the factorial for");
                    //Stores users answer in intnum variable
                    intnum = new Scanner(System.in).nextInt();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch6 = true;
                }
            }
            //boolTryCatch is the boolean variable controlling the loop
            while(boolTryCatch6);
            
            //calls method and sends variable to method and saves return in intanswer variable
            intanswer = factorial(intnum);
            
            //outputs the following to the user
            System.out.println("The factorial is "+intanswer);
            
            //ends loop
            boolTryCatch = false;
        }
        //if neither circumference, acceleration and factorial the following program runs and the loop repeats
        else 
        {
            System.out.println("Error, please enter either circumference, acceleration or factorial"); boolTryCatch = true;  
        }
        }
        //variable that controls loop
        while(boolTryCatch);
        
        //While loop that 
        do
        {
            //outputs the following to the user
            System.out.println("Would you like to calculate something else");
            System.out.println("Please enter yes or no");
            //Stores users answer stryesorno variable
            stryesorno = new Scanner(System.in).next().toLowerCase();
            //Switch statement that decided of the program will repeat or not
            switch (stryesorno)
            {
                //if user enters yes the program repeats and the loop that holds this ends
                case "yes" :boolTryCatch8 = false; boolTryCatch7 = true;break;
                //if user enters yes the program ends and the loop that holds this ends
                case "no" :boolTryCatch8 = false; boolTryCatch7 = false;break;
                //if neither yes or no is answered the following runs and the booltrycatch8 loop repeats
                default : System.out.println("Error, please enter either yes or no"); boolTryCatch8 = true; 
            }
        }
        //variable that controls the loop
        while (boolTryCatch8);
    }
    //variable that controls the loop
    while(boolTryCatch7);
    }
    //non void method the calculates circumference with the input of radius  
    public static  double  circumference(double dblRadius)
    { 
        //variable holding the circumference 
        double dblCircum ;
        
        //calculating circumference 
        dblCircum = (dblRadius*2*Math.PI);
        
        //returning the circumference
        return dblCircum;
        
    }
    //void method that calculates the acceleration with the users input of final velocity, intial velocity and the time it took
    public static void acceleration(float fltVelocityF2, float fltVelocityI2, float flttime)
    {
        //variable holding the acceleration
        float fltacceleration;
        
        //caculating the acceleration
        fltacceleration = (fltVelocityF2 - fltVelocityI2)/flttime ;
        
        //outputs the following
        System.out.printf("The acceleration is %.4f",fltacceleration);
        System.out.println(" meters a second squared");
    }
    //non void method that calculates the factorial of a number
    public static int factorial(int intfactorial)
    {
       // variable that holds the factorial as it is being calculated
      int  intproduct = 1;
      //for loop that calculated factorial by multiplying 1 x 1 then the answer of that times 2 and repeating that until the factorial number
        for (int count=1; count<=intfactorial; count++)
      {
          intproduct = intproduct*count;
      }
      //returns the factorial back to the program
      return intproduct;
    }
}

