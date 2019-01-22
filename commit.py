from os import *
import time

chdir("C:\\Users\\zhuan_z6tlgsj\\Documents\\OI\\source")
system("git add --all")
system("git commit -m \"Backup : "+time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+"\"")
system("git push -u origin master")
