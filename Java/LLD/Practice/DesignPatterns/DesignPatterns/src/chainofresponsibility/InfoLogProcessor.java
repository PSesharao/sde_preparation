package chainofresponsibility;

public class InfoLogProcessor extends LogProcessor{
    public InfoLogProcessor(LogProcessor loggerProcessor) {
        super(loggerProcessor);
    }

    public void log(int logLevel , String message ) {
        // If it is the current request then handle it here
        if(logLevel == INFO ){
            System.out.println("INFO : " + message );
        }else{  // Otherwise let the parent know so that it will carry to next nested object
            super.log(logLevel , message );
        }
    }

}
