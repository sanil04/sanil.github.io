
/**
 * Description: Outputs Movie information
 *
 * Author: Sanil Srivastava
 * Date: March 29th 2021
 */
public class movie
{
   String strTitle, strDirector, strGenre;
   short shrYearReleased;
   
   movie(String title, String director, String genre, short year)
   {
       this.strTitle = title;
       this.strDirector = director;
       this.strGenre = genre;
       this.shrYearReleased = year;
   }
   
   movie()
   {
       this.strTitle = "unknown";
       this.strDirector = "unknown";
       this.strGenre = "unknown";
       this.shrYearReleased = 0;
   }
   public String toString()
   {
       return "Title: "+this.strTitle+"\nDirector: "+this.strDirector+"\nGenre: "+this.strGenre+"\nYear of Release: "+this.shrYearReleased;
       
   }
}
