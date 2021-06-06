
Program Trivia_Game;

{programmer: Sanil Srivastava}
{date: Januarary 2020)
{This program is a 5 question trivia game the gives the player 3 chances per questions and
gives the player points depending on how many tries it takes them to get the answer}

Const
									{These are the answers for the 5 questions}
  answer1 = 9;  {The first question is a math question so the answer is an integer number}
  answer2 = 'd'; {The other four questions are multiple choice questions so the answers are letters}
  answer3 = 'c';
  answer4 = 'a';
  answer5 = 'd';
Var

  ready : Char;     {These two variables are used to ask the player if he is ready to play and to start the game}
  readytoplay : Boolean;
  points : Integer;      {This variable counts the amount of points the player has throughout the game}
  correctanswers : Integer;   {This variable counts the number of correct answers the player gets}
	
  wrongguess1 : Integer;  {This variable counts the number of wrong gueses for the first question}
  guess1 : Real;    {This variable is the players guess for question 1. Since its a math question the variable is real}
  question1 : Boolean;     {This variable ends the loop that holds the question}
	
  wrongguess2 : Integer;     {This variable counts the number of wrong gueses for the second question}
  guess2 : Char;             {This variable is the players guess for question 2. Since its a multiple choice question the variable is a char}
  question2 : Boolean;       {This variable ends the loop that holds the question}
	
  wrongguess3 : Integer;    {This variable counts the number of wrong gueses for the third question}
  guess3 : Char;            {This variable is the players guess for question 3. Since its a multiple choice question the variable is a char}
  question3 : Boolean;        {This variable ends the loop that holds the question}
	
  wrongguess4 : Integer;      {This variable counts the number of wrong gueses for the fourth question}
  guess4 : Char;             {This variable is the players guess for question 4. Since its a mutiple choice question the variable is a char}
  question4 : Boolean;       {This variable ends the loop that holds the question}
	
  wrongguess5 : Integer;  {This variable counts the number of wrong gueses for the fifth question}
  guess5 : Char;          {This variable is the players guess for question 5. Since its a multiple choice question the variable is a char}
  question5 : Boolean;   {This variable ends the loop that holds the question}
	
Begin


	readytoplay := False;  {this the boolean variable that controls the loop} 
  Repeat
    Writeln('Are you ready to play the best trivia game ever'); {Tells the user that this is a trivia game and asks them if they are ready to start}          
    Writeln;
    Writeln('Please answer everything without any capital letters for the entire game'); { this is a rule for the player}
    Writeln;
    Writeln('Please enter y for yes and n for no');      {Tells the user what their valid options for input are}
    Readln(ready); {this variable holds the users input}
    Writeln;
    Case ready Of          {This case statement controls the two options that the user has}
      'y': readytoplay := True; {when the user enters y the boolean variable readytoplay will be true and the game will start}
      'n': Writeln('You have no choice. Please enter y to continue'); {when the user enters n the boolean variable readytoplay will remain false and the loop will reapeat}
      Else
        Writeln('Please enter y to continue'); {This is if the user doesnt enter a valid input. The loop will repeat} 
    End
  Until readytoplay; {This is so the loop will repeat until the boolean variable is true}
	
	{This loop is made so that it ends when the user gets the answer right or reaches the maximum amont of four guesses}
  question1 := False; {this is the boolean variable that controls the loop for the first question}
  Repeat
    Writeln('Question 1. What is 6/2(1+2)?'); {This is the first question that the user sees}
    Readln(guess1);      {This is the users input for that question}
    Writeln;
{This if statement controls the amount of points the user gets based on how many tries it takes them to get the right answer}
		
    If (guess1 = answer1) And (wrongguess1 = 0)Then     {If the user gets the answer right on their first time this will start}
      Begin
        Writeln;
        Writeln('Excellent! You got the answer right on your first try and got 3 points');
        Writeln;
        points := points+3;     {This gives them three points for getting the answer right on their first try}
        correctanswers := correctanswers+1;     {This adds 1 correct answer to the number of correct answers they have}
        question1 := True;     {This will end the loop that is holding the question}
      End
    Else If (guess1 = answer1) And (wrongguess1 = 1) Then  {If the user gets the answer right on their second try this will start}
           Begin
             Writeln;
             Writeln('Great job! You got the answer right on your second try and got 2 points');
             Writeln;
             points := points+2;       {This gives them two points for getting the answer right on their second try}
             correctanswers := correctanswers+1;    {This adds 1 correct answer to the number of correct answers they have}
             question1 := True;       {This will end the loop that is holding the question}
           End
    Else If (guess1 = answer1) And (wrongguess1 = 2) Then {If the user gets the answer right on their third try this will start}
           Begin
             Writeln;
             Writeln('You got the answer right on your third try and got 1 point');
             Writeln;
             points := points+1;          {This gives them one point for getting the answer right on their third try}
             correctanswers := correctanswers+1;    {This adds 1 correct answer to the number of correct answers they have}
             question1 := True;        {This will end the loop that is holding the question}
           End
    Else If (wrongguess1=2)Then  {If the user reaches the maximum amount of guesses without getting the answer right this will start}
           Begin
             Writeln;
             Writeln('You have reached the maximum amount of guesses');      {Tells the user they have reached the maximum amoun of guesses}
             Writeln('The answer is 9');         {Tells the user the answer}
             Writeln;
             Question1 := True; {This will end the loop that is holding the question}
           End
    Else     {If the user gets the answer wrong and hasnt reached the maximum amount of guesses this will start}
      Begin
        Writeln('Wrong answer. Please try again');
        Writeln;
        wrongguess1 := wrongguess1+1;    {Adds a wrong guess to the amount of wrong guesses for the first question. This is used to count the amount of guesses}
					 {The loop will repeat}
      End;
  Until (question1);  {Once the user gets the answer right or reaches the maximum amount of guesses the loop will end because the boolean variable will be true} 




	
  question2 := False;          {This questions is structured the exact same as the first question except that its multiple choiced}
  Repeat
    Writeln('Question 2. How long is New Zealands Ninety Mile Beach?');
    Writeln('a : 4 Miles');                   {Multiple choice options}
    Writeln('b : 90 Miles');
    Writeln('c : 86.34 Miles');
    Writeln('d : 55 Miles');
    Writeln('Please answer with coresponding letter');
    Readln(guess2);
    Writeln;
    If (guess2 = answer2) And (wrongguess2 = 0)Then
      Begin
        Writeln;
        Writeln('Excellent! You got the answer right on your first try and got 3 points');
        Writeln;
        points := points+3;
        correctanswers := correctanswers+1;
        question2 := True;
      End
    Else If (guess2 = answer2) And (wrongguess2 = 1) Then
           Begin
             Writeln;
             Writeln('Great job! You got the answer right on your second try and got 2 points');
             Writeln;
             points := points+2;
             correctanswers := correctanswers+1;
             question2 := True;
           End
    Else If (guess2 = answer2) And (wrongguess2 = 2) Then
           Begin
             Writeln;
             Writeln('You got the answer right on your third try and got 1 point');
             Writeln;
             points := points+1;
             correctanswers := correctanswers+1;
             question2 := True;
           End
    Else If (wrongguess2=2) Then
           Begin
             Writeln;
             Writeln('You have reached the maximum amount of guesses');
             Writeln('The answer is d');
             Writeln;
             Question2 := True;
           End
    Else
      Begin
        Writeln('Wrong answer. Please try again');
        Writeln;
        wrongguess2 := wrongguess2+1;
      End;
  Until (question2);




	
  question3 := False;       {This questions is structured the exact same as the first question except that its multiple choiced}
  Repeat
    Writeln('Question 3. What colour is an airplanes blackbox');
    Writeln('a : Red');
    Writeln('b : Grey');
    Writeln('c : Orange');
    Writeln('d : Black');
    Writeln('Please answer with coresponding letter');
    Readln(guess3);
    Writeln;
    If (guess3 = answer3) And (wrongguess3 = 0)Then
      Begin
        Writeln;
        Writeln('Excellent! You got the answer right on your first try and got 3 points');
        Writeln;
        points := points+3;
        correctanswers := correctanswers+1;
        question3 := True;
      End
    Else If (guess3 = answer3) And (wrongguess3 = 1) Then
           Begin
             Writeln;
             Writeln('Great job! You got the answer right on your second try and got 2 points');
             Writeln;
             points := points+2;
             correctanswers := correctanswers+1;
             question3 := True;
           End
    Else If (guess3 = answer3) And (wrongguess3 = 2) Then
           Begin
             Writeln;
             Writeln('You got the answer right on your third try and got 1 point');
             Writeln;
             points := points+1;
             correctanswers := correctanswers+1;
             question3 := True;
           End
    Else If (wrongguess3=2) Then
           Begin
             Writeln;
             Writeln('You have reached the maximum amount of guesses');
             Writeln('The answer is c');
             Writeln;
             Question3 := True;
           End
    Else
      Begin
        Writeln('Wrong answer. Please try again');
        Writeln;
        wrongguess3 := wrongguess3+1;
      End;
  Until (question3);




	
  question4 := False;            {This questions is structured the exact same as the first question except that its multiple choiced}
  Repeat
    Writeln('Question 4. Where did the spanish flu originate?');
    Writeln('a : U.S');
    Writeln('b : Spain');
    Writeln('c : India');
    Writeln('d : Mexico');
    Writeln('Please answer with coresponding letter');
    Readln(guess4);
    Writeln;
    If (guess4 = answer4) And (wrongguess4 = 0)Then
      Begin
        Writeln;
        Writeln('Excellent! You got the answer right on your first try and got 3 points');
        Writeln;
        points := points+3;
        correctanswers := correctanswers+1;
        question4 := True;
      End
    Else If (guess4 = answer4) And (wrongguess4 = 1) Then
           Begin
             Writeln;
             Writeln('Great job! You got the answer right on your second try and got 2 points');
             Writeln;
             points := points+2;
             correctanswers := correctanswers+1;
             question4 := True;
           End
    Else If (guess4 = answer4) And (wrongguess4 = 2) Then
           Begin
             Writeln;
             Writeln('You got the answer right on your third try and got 1 point');
             Writeln;
             points := points+1;
             correctanswers := correctanswers+1;
             question4 := True;
           End
    Else If (wrongguess4=2) Then
           Begin
             Writeln;
             Writeln('You have reached the maximum amount of guesses');
             Writeln('The answer is a');
             Writeln;
             Question4 := True;
           End
    Else
      Begin
        Writeln('Wrong answer. Please try again');
        Writeln;
        wrongguess4 := wrongguess4+1;
      End;
  Until (question4);




	
  question5 := False;          {This questions is structured the exact same as the first question except that its multiple choiced}
  Repeat
    Writeln('Question 5. How long did the 100 year war last?');
    Writeln('a : 97');
    Writeln('b : 100');
    Writeln('c : 104');
    Writeln('d : 116');
    Writeln('Please answer with coresponding letter');
    Readln(guess5);
    Writeln;
    If (guess5 = answer5) And (wrongguess5 = 0)Then
      Begin
        Writeln;
        Writeln('Excellent! You got the answer right on your first try and got 3 points');
        Writeln;
        points := points+3;
        correctanswers := correctanswers+1;
        question5 := True;
      End
    Else If (guess5 = answer5) And (wrongguess5 = 1) Then
           Begin
             Writeln;
             Writeln('Great job! You got the answer right on your second try and got 2 points');
             Writeln;
             points := points+2;
             correctanswers := correctanswers+1;
             question5 := True;
           End
    Else If (guess5 = answer5) And (wrongguess5 = 2) Then
           Begin
             Writeln;
             Writeln('You got the answer right on your third try and got 1 point');
             Writeln;
             points := points+1;
             correctanswers := correctanswers+1;
             question5 := True;
           End
    Else If (wrongguess5=2) Then
           Begin
             Writeln;
             Writeln('You have reached the maximum amount of guesses');
             Writeln('The answer is d');
             Writeln;
             Question5 := True;
           End
    Else
      Begin
        Writeln('Wrong answer. Please try again');
        Writeln;
        wrongguess5 := wrongguess5+1;
      End;
  Until (question5);




	
  Writeln;
  Writeln('You got ',correctanswers,' answers right out of a max of 5');     {This outputs the amount of answers the user got right}
  Writeln;
  If (points = 15) Then        {This outputs the amount of points the user gets and changes thw wording depending on how they did}
    Writeln('You got a perfect score of 15 points out of a max of 15')
  Else If (points>=12) And (points<=14) Then
         Writeln('You got an great score of ',points,' out of a max of 15')
  Else If (points>=9) And (points<=11) Then
         Writeln('You got a good score of ',points,' out of a max of 15')
  Else If (points>=6)And (points<=8) Then
         Writeln('You got a okay score of ',points,' out of a max of 15')
  Else If (points>=1) And (points<=5) Then
         Writeln('You got a bad score of ',points,' out of a max of 15')
  Else
    Writeln('You got a horrible score of ',points,' out of a max of 15');
  Writeln;
  Writeln;
  Readln;
  Writeln;
End.