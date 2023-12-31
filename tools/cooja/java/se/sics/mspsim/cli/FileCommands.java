package se.sics.mspsim.cli;

import java.util.HashMap;
import se.sics.mspsim.util.ComponentRegistry;

public class FileCommands implements CommandBundle {

    private final HashMap<String,Target> fileTargets = new HashMap<>();

    @Override
    public void setupCommands(final ComponentRegistry registry, CommandHandler handler) {
        // TODO: this should also be "registered" as a "sink".
        // probably this should be handled using ">" instead!
        handler.registerCommand(">", new FileTargetCommand(fileTargets,
            null, "<filename>", false, false));

        handler.registerCommand(">>", new FileTargetCommand(fileTargets,
            null, "<filename>", false, true));

        handler.registerCommand("tee", new FileTargetCommand(fileTargets,
            "redirect to file and standard out", "<filename>", true, true));

        handler.registerCommand("fclose", new BasicCommand("close the specified file", "<filename>") {
          @Override
          public int executeCommand(CommandContext context) {
            String name = context.getArgument(0);
            Target ft = fileTargets.get(name);
            if (ft != null) {
              context.out.println("Closing file " + name);
              ft.close();
              return 0;
            }
            context.err.println("Could not find the open file " + name);
            return 1;
          }
        });

        handler.registerCommand("files", new BasicCommand("list open files", "") {
          @Override
          public int executeCommand(CommandContext context) {
            Target[] files = null;
            synchronized (fileTargets) {
                if (!fileTargets.isEmpty()) {
                    files = fileTargets.values().toArray(new Target[0]);
                }
            }
            if (files == null) {
              context.out.println("There are no open files.");
            } else {
              for (var type : files) {
                context.out.println(type.getStatus());
              }
            }
            return 0;
          }
        });
    }

}
