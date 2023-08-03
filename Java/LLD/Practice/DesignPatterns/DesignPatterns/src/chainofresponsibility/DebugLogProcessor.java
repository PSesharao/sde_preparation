package chainofresponsibility;

public class DebugLogProcessor extends LogProcessor{
    public DebugLogProcessor(LogProcessor loggerProcessor) {
        super(loggerProcessor);
    }

    public void log(int logLevel , String message ) {
        // If it is the current request then handle it here
        if(logLevel == DEBUG ){
            System.out.println("DEBUG : " + message );
        }else{  // Otherwise let the parent know so that it will carry to next nested object
            super.log(logLevel , message );
        }
    }

}
