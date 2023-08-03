package chainofresponsibility;

public class ChainOfResponsibilityDesignPattern {
    public static void main(String[] args) {

        // This is the chain of objects , at last we have given as null if it does not match with any
        LogProcessor logProcessor = new InfoLogProcessor(new DebugLogProcessor( new ErrorLogProcessor(null))) ;

        logProcessor.log(LogProcessor.ERROR , "Error Log");
        logProcessor.log(LogProcessor.INFO , "Info Log");
        logProcessor.log(LogProcessor.DEBUG , "Debug Log");
        logProcessor.log(-1, "Out of request Log"); // It does not handle any request

    }
}
