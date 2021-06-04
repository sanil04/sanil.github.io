
/**
 * Description: This program is a multiple choice physics quix
 *
 * Name: Sanil Srivastava
 * Date: March 22nd 2021
 */

//To be able to use scanner for input
import java.util.Scanner;
public class Sanil_Assignment5_MultipleChoice
{
    public static void main(String[] args)
    {
        //Brings in Scanner to be used
        Scanner input =new Scanner(System.in);
        
        //character array variable holding users input of a, b, c or d
        char[] chrAnswer = new char [10];
        //character array variable holding the correct answer with answer key
        char[] chrCorrect = new char[]{'a','b','d','a','d','c','d','b','d','a'};
        //byte variable used for counting how many times the loop has happened and what question its on
        byte bytcount = 0;
        //byte variable used for counting how many times the loop has happened and what questions answer its checking
        byte bytcount2 = 0;
        //byte variable holding the percentage of answers 
        byte bytpercentage = 0;
        //boolean variable controlling loop for try and catch
        boolean booltrycatch = false;
        //boolean variable controlling loop for try and catch
        boolean boolTryCatch2 = true;
        //boolean variable controlling the loop with the questions
        boolean boolquestions = true;
        //boolean variable controlling the loop that checks answers
        boolean boolloop = true;
        //boolean variable that controls an if statement 
        boolean boolincorrect = false;
        //byte array variable that stores which questions are answered incorrectly 
        byte[] bytincorrect = new byte[10]; 
        //string holding users response of yes or no
        String stryesorno ;
        
        //Clears terminal
        System.out.println('\u000C');
        
        //outputs the following to user
        System.out.println("This is a physics quiz with ten multiple choice questions");
        
        //while loop that loops for each question
        do
        {
            //while loop for try and catch 
            do
            {
                //if count = 0 the following is outputted
                if (bytcount == 0)
                {
                    System.out.println("1.Which term describes applying a force on an object that displaces the object in the direction of the force or a component of force?");
                    System.out.println("a = mechanical work");
                    System.out.println("b = energy");
                    System.out.println("c = efficiency");
                    System.out.println("d = power");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 1 the following is outputted
                else if (bytcount == 1)
                {
                    System.out.println("2.Which term describes a form of energy an object possesses because of its position in relation to forces in its environment?");
                    System.out.println("a = thermal energy");
                    System.out.println("b = potential energy");
                    System.out.println("c = kinetic energy");
                    System.out.println("d = nuclear energy");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 2 the following is outputted
                else if (bytcount == 2)
                {
                    System.out.println("3.About how much power does a sprinter produce if he transforms 2.70 kJ of chemical energy from food into kinetic energy and thermal energy in 14.0s ");
                    System.out.println("a = 5.2 W");
                    System.out.println("b = 37.8 W");
                    System.out.println("c = 0.2 W");
                    System.out.println("d = 193 W");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 3 the following is outputted
                else if (bytcount == 3)
                {
                    System.out.println("4.Calculate the Kinetic energy of a 160g hockey puck moving with a velocity of 29 m/s.");
                    System.out.println("a = 67 J");
                    System.out.println("b = 56 J");
                    System.out.println("c = 38 J");
                    System.out.println("d = 49 J");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 4 the following is outputted
                else if (bytcount == 4)
                {
                    System.out.println("5.Mohammed uses 686 N of force to hold his body in the bottom of a push-up position 25 cm above the ground, for 30 seconds. How much work did Mohammed do?");
                    System.out.println("a = 5.7 J");
                    System.out.println("b = 170 J");
                    System.out.println("c = 17000 J");
                    System.out.println("d = None");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 5 the following is outputted
                else if (bytcount == 5)
                {
                    System.out.println("6.A toaster uses 24 000 J of energy to provide 21 000 J of heat to your bread. Calculate the % efficiency of the toaster. ");
                    System.out.println("a = 23%");
                    System.out.println("b = 114%");
                    System.out.println("c = 88%");
                    System.out.println("d = 100%");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 6 the following is outputted
                else if (bytcount == 6)
                {
                    System.out.println("7.Which unit below is not a possible unit for power?");
                    System.out.println("a = W");
                    System.out.println("b = J/min");
                    System.out.println("c = Nm/s");
                    System.out.println("d = N/s");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 7 the following is outputted
                else if (bytcount == 7)
                {
                    System.out.println("8.William is carrying a 9.20 kg box, which he sets down from a height of 1.50 m. How much work is done in the process?");
                    System.out.println("a = 13.8 J");
                    System.out.println("b = -135 J");
                    System.out.println("c = 135 J");
                    System.out.println("d = -13.8 J");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 8 the following is outputted
                else if (bytcount == 8)
                {
                    System.out.println("9.What is the potential energy of a 69 kg person sitting at the top of a 28 m Ferris wheel?");
                    System.out.println("a = 20 kJ");
                    System.out.println("b = 18 kJ");
                    System.out.println("c = 21 kJ");
                    System.out.println("d = 19 kJ");
                    System.out.println("Please enter a, b, c or d");
                }
                //if count = 9 the following is outputted
                else if (bytcount == 9)
                {
                    System.out.println("10.The specific heat of copper is 380.0 J/kg C. What will happen to the temperature of 12.0 g of copper if it loses 12.0 J of thermal energy?");
                    System.out.println("a = -2.63 C");
                    System.out.println("b = 2.63 C");
                    System.out.println("c = 0.38 C");
                    System.out.println("d = -0.38 C");
                    System.out.println("Please enter a, b, c or d");
                    boolquestions = false;
                }
                //stores the user response in chranswer array and converts to lower case
                chrAnswer[bytcount] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                //if statement that acts as an try and catch
                //if chranswer array variable is a, b, c or d the following happens
                if (chrAnswer[bytcount] == 'a' || chrAnswer[bytcount] =='b'|| chrAnswer[bytcount] =='c'|| chrAnswer[bytcount] =='d')
                {
                    //the count goes up one
                    bytcount = (byte)(bytcount +1);
                    //ends booltrycatch loop
                    booltrycatch = false;
                }
                //if user does not enter a, b, c or d the following runs
                else
                {
                    //outputs the following to the user
                    System.out.println("Error, please enter either a, b, c or d");
                    //causes booltrycatch to repeat
                    booltrycatch = true;
                }
                //Variable controlling loop
            }
            while(booltrycatch); 
            //Variable controlling loop
        }
        while(boolquestions);
        
        
        //while loop that check answers
        while(boolloop)
        {
            //if the answer and users input is the same the following happens
            if (chrAnswer[bytcount2] == chrCorrect[bytcount2])
            {
                //adds 10 to the percentage of right answers
                bytpercentage = (byte)(bytpercentage +10);
                //outputs that the question was answered correctly
                System.out.println("You answered question "+(bytcount2+1)+" correctly");
            }
            //if the answer and users input is different the following happens
            else
            {
                //outputs the question was answered inccorectly
                System.out.println("You answered question "+(bytcount2+1)+" incorrectly");
                //boolincorrect variable is true so that the section asking if the questions that were answered inccorectly repeat
                boolincorrect = true;
                //sets array variable question number as 1 which means incorrect
                bytincorrect[bytcount2] = 1;
            }
            //ends loop when done last question
            if(bytcount2 == 9)
            {
                boolloop = false;
            }
            //adds one to the count
            if(bytcount2 <=8)
            {
                bytcount2 = (byte)(bytcount2 + 1); 
            }
        }
        
        
        //outputs the percentage of correctly answered questions to the user
        System.out.println("You got "+bytpercentage+"% of the questions right");
        
        if (boolincorrect)
        {
            //While loop that that acts as loop for the try and catch 
            do
            {
                //outputs the following to the user
                System.out.println("Would you like to retry the question you answered incorrectly");
                System.out.println("Please enter yes or no");
                //Stores users answer stryesorno variable
                stryesorno = new Scanner(System.in).next().toLowerCase();
                //Switch statement that decides if the method will run
                switch (stryesorno)
                {
                    //if user enters yes the method runs and the loop that holds this ends
                    case "yes" :boolTryCatch2 = false;retry(bytincorrect); break;
                    //if user enters no the method doesnt run and the loop that holds this ends
                    case "no" :boolTryCatch2 = false;break;
                    //if neither yes or no is answered the following runs and the booltrycatch2 loop repeats
                    default : System.out.println("Error, please enter either yes or no"); boolTryCatch2 = true; 
                }
            }
            //variable that controls the loop
            while (boolTryCatch2);
            
        }
        
    }
    //method that asks user the questions they answered incorrectly
    public static void retry(byte[] bytIncorrect2)
    {
        //character array variable that stores users input
        char[] chranswer2 = new char [10];
        //character array variable that stores the correct answer
        char[] chrcorrect2 = new char[]{'a','b','d','a','d','c','d','b','d','a'};
        //boolean variable that is used to loop try ans catch
        boolean booltrycatch = false;
        // byt variable used as a count
        byte bytcount = 0;
        //boolean variable user for loop in answer check
        boolean boolloop = true;
        

        //if the first question was answered incorrectly the following runs
        if(bytIncorrect2[0] == 1)
        {
            //while loop that loops try and catch
            do
            {
                //outputs the following to the user
                System.out.println("1.Which term describes applying a force on an object that displaces the object in the direction of the force or a component of force?");
                System.out.println("a = mechanical work");
                System.out.println("b = energy");
                System.out.println("c = efficiency");
                System.out.println("d = power");
                System.out.println("Please enter a, b, c or d");
                //stores users input in chranswer2 character array variable
                chranswer2[0] = new Scanner(System.in).next().toLowerCase().charAt(0);
                
                //if statement used as a try and catch
                //if chranswer2 array variable is a, b, c or d the following happens
                if (chranswer2[0] == 'a' || chranswer2[0] =='b'|| chranswer2[0] =='c'|| chranswer2[0] =='d')
                {
                    //ends loop
                    booltrycatch = false;
                }
                //if chranswerw array variable is not a, b, c or d the following happens
                else
                {
                    //the following is outputed 
                    System.out.println("Please enter either a, b, c or d");
                    //loop repeats
                    booltrycatch = true;
                }
                //variable controlling loop
            }
            while(booltrycatch);
        }
        else
        {
            //shows the question was answered correctly on the first try
            chranswer2[0] = 'e' ;
        }
        //exact some logic as the first question but for question two
        if(bytIncorrect2[1] == 1)
        {
            
            do
            {
                System.out.println("2.Which term describes a form of energy an object possesses because of its position in relation to forces in its environment?");
                System.out.println("a = thermal energy");
                System.out.println("b = potential energy");
                System.out.println("c = kinetic energy");
                System.out.println("d = nuclear energy");
                System.out.println("Please enter a, b, c or d");
                chranswer2[1] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[1] == 'a' || chranswer2[1] =='b'|| chranswer2[1] =='c'|| chranswer2[1] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[1] = 'e' ;
        }
        //exact some logic as the first question but for question three
        if(bytIncorrect2[2] == 1)
        {
            do
            {
                
                System.out.println("3.About how much power does a sprinter produce if he transforms 2.70 kJ of chemical energy from food into kinetic energy and thermal energy in 14.0s ");
                System.out.println("a = 5.2 W");
                System.out.println("b = 37.8 W");
                System.out.println("c = 0.2 W");
                System.out.println("d = 193 W");
                System.out.println("Please enter a, b, c or d");
                chranswer2[2] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[2] == 'a' || chranswer2[2] =='b'|| chranswer2[2] =='c'|| chranswer2[2] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[2] = 'e' ;
        }
        //exact some logic as the first question but for question four
        if(bytIncorrect2[3] == 1)
        {
            do
            {
                System.out.println("4.Calculate the Kinetic energy of a 160g hockey puck moving with a velocity of 29 m/s.");
                System.out.println("a = 67 J");
                System.out.println("b = 56 J");
                System.out.println("c = 38 J");
                System.out.println("d = 49 J");
                System.out.println("Please enter a, b, c or d");
                chranswer2[3] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[3] == 'a' || chranswer2[3] =='b'|| chranswer2[3] =='c'|| chranswer2[3] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[3] = 'e' ;
        }
        //exact some logic as the first question but for question five
        if(bytIncorrect2[4] == 1)
        {
            do
            {
                System.out.println("5.Mohammed uses 686 N of force to hold his body in the bottom of a push-up position 25 cm above the ground, for 30 seconds. How much work did Mohammed do?");
                System.out.println("a = 5.7 J");
                System.out.println("b = 170 J");
                System.out.println("c = 17000 J");
                System.out.println("d = None");
                System.out.println("Please enter a, b, c or d");
                chranswer2[4] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[4] == 'a' || chranswer2[4] =='b'|| chranswer2[4] =='c'|| chranswer2[4] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[4] = 'e' ;
        }
        //exact some logic as the first question but for question six
        if(bytIncorrect2[5] == 1)
        {
            do
            {
                System.out.println("6.A toaster uses 24 000 J of energy to provide 21 000 J of heat to your bread. Calculate the % efficiency of the toaster. ");
                System.out.println("a = 23%");
                System.out.println("b = 114%");
                System.out.println("c = 88%");
                System.out.println("d = 100%");
                System.out.println("Please enter a, b, c or d");
                chranswer2[5] = new Scanner(System.in).next().toLowerCase().charAt(0);

                if (chranswer2[5] == 'a' || chranswer2[5] =='b'|| chranswer2[5] =='c'|| chranswer2[5] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[5] = 'e' ;
        }
        //exact some logic as the first question but for question seven
        if(bytIncorrect2[6] == 1)
        {
            do
            {
                System.out.println("7.Which unit below is not a possible unit for power?");
                System.out.println("a = W");
                System.out.println("b = J/min");
                System.out.println("c = Nm/s");
                System.out.println("d = N/s");
                System.out.println("Please enter a, b, c or d");
                chranswer2[6] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[6] == 'a' || chranswer2[6] =='b'|| chranswer2[6] =='c'|| chranswer2[6] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[6] = 'e' ;
        }
        //exact some logic as the first question but for question eight
        if(bytIncorrect2[7] == 1)
        {
            do
            {
                
                System.out.println("8.William is carrying a 9.20 kg box, which he sets down from a height of 1.50 m. How much work is done in the process?");
                System.out.println("a = 13.8 J");
                System.out.println("b = -135 J");
                System.out.println("c = 135 J");
                System.out.println("d = -13.8 J");
                System.out.println("Please enter a, b, c or d");
                chranswer2[7] = new Scanner(System.in).next().toLowerCase().charAt(0);
            
                if (chranswer2[7] == 'a' || chranswer2[7] =='b'|| chranswer2[7] =='c'|| chranswer2[7] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[7] = 'e' ;
        }
        //exact some logic as the first question but for question nine
        if(bytIncorrect2[8] == 1)
        {
            
            do
            {
                System.out.println("9.What is the potential energy of a 69 kg person sitting at the top of a 28 m Ferris wheel?");
                System.out.println("a = 20 kJ");
                System.out.println("b = 18 kJ");
                System.out.println("c = 21 kJ");
                System.out.println("d = 19 kJ");
                System.out.println("Please enter a, b, c or d");
                chranswer2[8] = new Scanner(System.in).next().toLowerCase().charAt(0);
                
                if (chranswer2[8] == 'a' || chranswer2[8] =='b'|| chranswer2[8] =='c'|| chranswer2[8] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[8] = 'e' ;
        }
        //exact some logic as the first question but for question ten
        if(bytIncorrect2[9] == 1)
        {
            
            do
            {
                System.out.println("10.The specific heat of copper is 380.0 J/kg C. What will happen to the temperature of 12.0 g of copper if it loses 12.0 J of thermal energy?");
                System.out.println("a = -2.63 C");
                System.out.println("b = 2.63 C");
                System.out.println("c = 0.38 C");
                System.out.println("d = -0.38 C");
                System.out.println("Please enter a, b, c or d");
                chranswer2[9] = new Scanner(System.in).next().toLowerCase().charAt(0);
                
                if (chranswer2[9] == 'a' || chranswer2[9] =='b'|| chranswer2[9] =='c'|| chranswer2[9] =='d')
                {
                    booltrycatch = false;
                }
                else
                {
                    System.out.println("Please enter either a, b, c or d");
                    booltrycatch = true;
                }
            }
            while(booltrycatch);
        }
        else
        {
            chranswer2[9] = 'e' ;
        }
        
        //while loop that loops for each question to check answers
        while(boolloop)
        {
            //if users input is the same as the correct answer the following runs
            if (chranswer2[bytcount] == chrcorrect2[bytcount])
            {
                //outputs that the question was answered correctly
                System.out.println("You answered question "+(bytcount+1)+" correctly");
            }
            //if user entered the correct answer on his first time answering the question the following runs
            else if(chranswer2[bytcount] == 'e')
            {
                //nothing happens
            }
            //if question is answered inccorectly the following happens
            else
            {
                //outputs that the question was answered inccorectly
                System.out.println("You answered question "+(bytcount+1)+" incorrectly");
            }
            //when the last questions has been checked this code runs
            if(bytcount == 9)
            {
                //ends loop
                boolloop = false;
            }
            //if the count is below 8 the following runs
            if(bytcount <=8)
            {
                //adds one to the count
                bytcount = (byte)(bytcount + 1); 
            }
        }
    }
}
