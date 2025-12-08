package bfs;

import java.io.File;
import java.util.LinkedList;
import java.util.Queue;

public class EmptyDirectoryCleaner {
    public static void main(String[] args) {
        String rootDirectory = "C:\\Users\\SESH\\Desktop\\EmptyDirectory" ;
        deleteEmptyDirectories(new File(rootDirectory));
    }

    public static void deleteEmptyDirectories(File rootDirectory) {
        Queue<File> queue = new LinkedList<>();
        queue.add(rootDirectory);

        while (!queue.isEmpty()) {
            File currentDirectory = queue.poll();

            if (currentDirectory.isDirectory()) {
                File[] files = currentDirectory.listFiles();

                if (files == null || files.length == 0) {
                    if (!currentDirectory.delete()) {
                        System.err.println("Failed to delete directory: " + currentDirectory.getAbsolutePath());
                    } else {
                        // Check if parent directory is empty after deletion
                        File parentDirectory = currentDirectory.getParentFile();
                        if (parentDirectory != null && parentDirectory.isDirectory() && parentDirectory.listFiles().length == 0) {
                            queue.offer(parentDirectory);
                        }
                    }
                } else {
                    for (File file : files) {
                        queue.add(file);
                    }
                }
            }
        }
    }
}