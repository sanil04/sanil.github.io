
/**
 * Description: This program is a game in which the user tries to guess a randomly generated number between 1 and 100 and bets on how many tries it will take.
 *
 * Name: Sanil Srivastava
 * Date: 2021/2/26
 */
//To be able to use random number generator
import java.util.Random;
//To be able to use scanner for input
import java.util.Scanner;
public class Sanil_GG3
{
    public static void main(String[] args)
    {
        //Brings in random number generator to be used
        Random rand = new Random(); 
        //Brings in random number generator to be used
        Scanner input =new Scanner(System.in);
        
        //Byte variable holding the users guess
        byte bytGuess = 101;
        //Integer variable holding the randomly generated number
        int intRandNum = rand.nextInt(100);
        //Boolean variable that allows the try and catch to loop 
        boolean boolTryCatch = false;
        //Boolean variable that allows the try and catch to loop 
        boolean boolTryCatch2 = false;
        //Integer variable holding the users bet in points
        int intbet = 0;
        //Integer variable holding the # of attempts the user took to guess the random number
        int intattempt = 0;
        
        
        
        //Clears terminal
        System.out.println('\u000C');
        
        
        //Outputs the following to the user
        System.out.println("This program will generate a random number between 1-100 which it will be your job to guess");
        
        
        
        //While loop for the try and catch so if the user does not input a number the user is given another chance
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("How many points would you like to bet");
                    //Stores users answer in intbet variable
                    intbet = new Scanner(System.in).nextInt();
                    //Ends loop
                    break;
                }
                //If users input is not a number the following code happens
                catch (Exception e)
                {
                    //Outputs the following to the user
                    System.out.println("Please enter a number");
                    //Causes loop to repeat
                    boolTryCatch = true;
                }
            }
            //boolTryCatch is the boolean variable controlling the loop
            while(boolTryCatch);
        
            
            
            
            
        //for loop that will run 10 times unless user inputs incorrect information
        for (int count = 1; count<=10; count++)
        {
            //While loop for the try and catch so if the user does not input a number the user is given another chance
            do
            {
                //Try and catch structure to make sure users input is a number
                try
                {
                    //Outputs the following to the user
                    System.out.println("Please guess a number between 1 and 100");
                    System.out.println("Attempt "+count);
                    //Stores users input in bytGuess variable
                    bytGuess = new Scanner(System.in).nextByte();
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
            //boolTryCatch is the boolean variable controlling the loop
            while(boolTryCatch2);
        
            
            
            
            //If statement that figures out whether users guess to low, to high or equal as well as making sure the number is between 1 and 100
            //If users guess is equal to the random number than the following section of program executes
            if (bytGuess == intRandNum && bytGuess<101 && bytGuess>0)
            {
                //Outputs the following to the user
                System.out.println("Congratulation you guessed the number");
                //Ends loop
                break;
            }
            //If users guess is lower than the random number than the following section of program executes
            else if (bytGuess < intRandNum && bytGuess<101 && bytGuess>0)
            {
                //Outputs the following to the user
                System.out.println("Your guess is too low");
            }
            //If users guess is higher than the random number than the following section of program executes
            else if (bytGuess > intRandNum && bytGuess<101 && bytGuess>0)
            {
                //Outputs the following to the user
                System.out.println("Your guess is too high");
            }
            //This is so that if the user enters a number that is not between 1 and 100 the program loops 
            else
            {
                //Allows the loop to run one more time because of improper input
                System.out.println("Error");
                count = count-1;
            }
            //makes intattempt and count variables equal
            intattempt = count+1;
        } 
        
        
        
        //If statement that determines the number of points the user was awarded depending on how many attempts the user takes
        //If user guesses the answer on their first attempt the following code executes
        if (intattempt >=0 && intattempt <=1)
        {
            //Outputs the following to the user
            System.out.println("Congrats you guessed the number on your 1st attempt");
            //Multiplies the amount of points bet by 100
            System.out.println("You now have "+(intbet*100)+" points"); 
        }
        //If user guesses the answer on their second attempt the following code executes
        else if (intattempt == 2)
        {
            //Outputs the following to the user
            System.out.println("Congrats you guessed the number on your 2nd attempt");
            //Multiplies the amount of points bet by 50
            System.out.println("You now have "+(intbet*50)+" points"); 
        }
        //If user guesses the answer on their third to fifth attempt the following code executes
        else if (intattempt >=3 && intattempt <=5)
        {
            //Outputs the following to the user
            System.out.println("Congrats you guessed the number in "+intattempt+" attempts");
            //Multiplies the amount of points bet by 10
            System.out.println("You now have "+(intbet*10)+" points"); 
        }
        //If user guesses the answer on their sixth to tenth attempt the following code executes
        else if (intattempt >=6 && intattempt <=10)
        {
            //Outputs the following to the user
            System.out.println("Congrats you guessed the number in "+intattempt+" attempts");
            //Amount of points bet stay the same
            System.out.println("You now have "+intbet+" points"); 
        }
        //If the user does not guess the code in ten attempts the following code executes
        else
        {
            //Outputs the following to the user
            System.out.println("You reached the maximum amount of attempts");
            //User loses what they bet
            System.out.println("You have 0 points");
        }
    }
}
