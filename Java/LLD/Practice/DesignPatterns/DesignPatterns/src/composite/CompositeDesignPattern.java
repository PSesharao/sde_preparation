package composite;

public class CompositeDesignPattern {

    public static void main(String[] args) {

        Directory movieRootDirectory =  new Directory("Movies") ;

        FileSystem subtitleFile = new File("english_subtitles.srt") ;
        movieRootDirectory.add(subtitleFile);

        Directory comedyFilmDirectory = new Directory("Comedy") ;

        FileSystem ben10Film = new File("Ben 10") ;

        comedyFilmDirectory.add(ben10Film);

        Directory actionFilmDirectory = new Directory("Action") ;

        FileSystem terminatorFilm = new File("Terminator") ;

        actionFilmDirectory.add(terminatorFilm);

        movieRootDirectory.add(comedyFilmDirectory);

        movieRootDirectory.add(actionFilmDirectory);

        movieRootDirectory.ls();

    }
}
