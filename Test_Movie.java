import java.util.Scanner;

/**
 * Description: Gathers movie information input
 *
 * Author: Sanil Srivastava
 * Date: March 29th 2021
 */
public class Test_Movie
{
    public static void main(String[] args)
    {
        byte bytNumMov = 0;
        String strTitle, strDirector, strGenre;
        short shrYearReleased = 0;
        movie[] movielist;
        
        System.out.println("This program asks information about movies and outputs in an organized manner");
        System.out.println("How many movies");
        bytNumMov = new Scanner(System.in).nextByte();
        
        movielist = new movie[bytNumMov];
        
        for (int count = 0; count<bytNumMov; count++)
        {
            System.out.println("What is the name of the movie");
            strTitle = new Scanner(System.in).nextLine();
            
            System.out.println("Who is the director of the movie");
            strDirector = new Scanner(System.in).nextLine();
            
            System.out.println("What is the genre of the movie");
            strGenre = new Scanner(System.in).nextLine();
            
            System.out.println("What is the year the movie was released");
            shrYearReleased = new Scanner(System.in).nextShort();
            
            movielist[count] = new movie(strTitle, strDirector, strGenre, shrYearReleased);
        }
        
        for (movie m: movielist)
        {
            System.out.println(m);
        }
        
    }
}
