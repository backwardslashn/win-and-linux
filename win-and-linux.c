#include <stdio.h>

typedef struct 
{
    char windows_command[40];
    char linux_command[40];
    char description[300];
} CommandMapping;

/* Global Array of Windows commands and their Linux equivalents with detailed descriptions.*/
CommandMapping commands[] = 
{
    {"cmd", "bash", "Command Prompt (cmd.exe) is the default shell in Windows, used for running batch scripts and system commands. In Linux, Bash (Bourne Again Shell) serves as the default command-line interface for managing files, executing scripts, and system administration."},
    {"powershell", "zsh", "PowerShell is a powerful Windows shell and scripting language, used for automation and configuration management. In Linux, Zsh (Z shell) is an extended version of Bash with more features, like better autocompletion and scripting capabilities."},
    {"calc", "bc", "Windows Calculator is a basic math tool. The Linux equivalent, 'bc' (Basic Calculator), is a command-line utility for performing advanced calculations and scripting arithmetic expressions."},
    {"notepad", "nano", "Notepad is a simple text editor in Windows. In Linux, Nano is a user-friendly command-line text editor useful for modifying configuration files and scripts."},
    {"mspaint", "gimp", "MS Paint is a simple image editing tool. GIMP (GNU Image Manipulation Program) is a powerful, open-source graphics editor in Linux."},
    {"taskmgr", "htop", "Task Manager is used to monitor running processes and resource usage. In Linux, 'htop' provides an interactive, real-time overview of system performance."},
    {"explorer", "nautilus", "File Explorer is the graphical interface for browsing files. 'Nautilus' (Files) is the default file manager for GNOME."},
    {"msconfig", "systemctl", "System Configuration allows users to control startup processes and boot options. 'systemctl' in Linux manages system services and startup settings."},
    {"winver", "lsb_release", "Windows Version displays OS version details. 'lsb_release' in Linux provides distribution and version information."},
    {"services.msc", "systemctl", "Services Manager lets users start, stop, and configure Windows services. 'systemctl' in Linux is used for managing systemd services and daemons."},
    {"eventvwr.msc", "journalctl", "Event Viewer logs system and application events. 'journalctl' in Linux retrieves and manages system logs from the journald service."},
    {"devmgmt.msc", "lshw", "Device Manager allows users to manage and update hardware drivers. In Linux, 'lshw' (List Hardware) provides detailed information about system hardware components."},
    {"firewall.cpl", "ufw", "Windows Firewall manages network security settings. 'ufw' (Uncomplicated Firewall) is a command-line tool for managing firewall rules in Linux."},
    {"diskmgmt.msc", "fdisk", "Disk Management is used for partitioning and managing storage devices. In Linux, 'fdisk' is a command-line tool for creating, modifying, and managing partitions."},
    {"regedit", "gconf-editor", "Registry Editor is used to modify Windows system settings. 'Gconf Editor' in Linux provides a graphical way to edit configuration settings."},
    {"taskschd.msc", "cron", "Task Scheduler is used to automate tasks in Windows. 'cron' is the Linux equivalent, allowing users to schedule and automate tasks."},
    {"dxdiag", "glxinfo", "DirectX Diagnostic Tool provides information about graphics and sound in Windows. 'glxinfo' in Linux provides OpenGL rendering and GPU information."},
    {"cleanmgr", "bleachbit", "Disk Cleanup removes unnecessary files in Windows. 'BleachBit' in Linux performs similar system cleanup functions."},
    {"snippingtool", "scrot", "Snipping Tool captures screenshots in Windows. 'scrot' is a command-line screenshot tool for Linux."},
    {"mstsc", "remmina", "Remote Desktop Connection allows Windows users to connect to remote machines. 'Remmina' is a Linux alternative for remote desktop access."}
};

int commandCount = sizeof(commands) / sizeof(commands[0]);

void listCommands()
{
    printf("\nAvailable Windows to Linux Command Mappings:\n");
    printf("| Windows_commands | | Linux_commands | | Description_commands |\n");
    
    for (int index = 0; index < commandCount; index++)
    {
        printf("%-20s -> %-15s - %s\n", commands[index].windows_command, commands[index].linux_command, commands[index].description);
    }
}

void searchCommands()
{
    char userInput[40];
    printf("\nSearch for a Windows or Linux command: ");
    scanf("%s", userInput);

    int commandFound = 0;

    for (int i = 0; i < commandCount; i++)
    {
        int found = 1;

        for (int index = 0; userInput[index] != '\0' && commands[i].windows_command[index] != '\0'; index++)
        {
            if (userInput[index] != commands[i].windows_command[index])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            printf("\nWindows Command: %s\n", commands[i].windows_command);
            printf("\nLinux Equivalent: %s\n", commands[i].linux_command);
            printf("Description: %s\n\n", commands[i].description);

            commandFound = 1;
            break;
        }
        
        found = 1;
        
        for (int index = 0; userInput[index] != '\0' && commands[i].linux_command[index] != '\0'; index++)
        {
            if (userInput[index] != commands[i].linux_command[index])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            printf("\nLinux Command: %s\n", commands[i].linux_command);
            printf("\nWindows Equivalent: %s\n", commands[i].windows_command);
            printf("Description: %s\n\n", commands[i].description);

            commandFound = 1;
            break;
        }
    }
    if (!commandFound)
    {
        printf("\nError: Command '%s' not found.\n", userInput);
    }
}

int main()
{
    int userMenu;
    while (1)
    {
        printf("\n\tSelect an option: ");
        printf("\n\t1: List all commands\n\t2: Search for a command\n\t3: Exit");
        printf("\n\n\tOption: ");
        
        scanf("%d", &userMenu);

        switch (userMenu)
        {
            case 1:
                listCommands();
            break;
            case 2:
                searchCommands();
            break;
            case 3:
                printf("\nExiting program...\n");
                return 0;
        }
    if (userMenu >= 1)
    {
        return 0;
    }
    }
}
