package chainofresponsibility;

public class ErrorLogProcessor extends  LogProcessor{
    public ErrorLogProcessor(LogProcessor loggerProcessor) {
        super(loggerProcessor);
    }

    public void log(int logLevel , String message ) {
        // If it is the current request then handle it here
        if(logLevel == ERROR ){
            System.out.println("ERROR : " + message );
        }else{  // Otherwise let the parent know so that it will carry to next nested object
            super.log(logLevel , message );
        }
    }
}
