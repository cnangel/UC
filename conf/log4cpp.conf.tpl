[log4cpp]
# --- categories ---
rootCategory=INFO, MAIN
additivity.rootCategory=false

category.uc=INFO, uc
additivity.uc=false

category.uc_access=INFO, uc_access
additivity.uc_access=false

category.screenlog=INFO, CONSOLE
additivity.screenlog=false


# --- CONSOLE ---
appender.CONSOLE=org.apache.log4cpp.ConsoleAppender
appender.CONSOLE.Threshold=INFO
appender.CONSOLE.layout=org.apache.log4cpp.PatternLayout
appender.CONSOLE.layout.ConversionPattern=%d{ISO8601} - %-5p [%t] - %m%n


# --- SCON ---
appender.SCON=org.apache.log4cpp.ConsoleAppender
appender.SCON.Threshold=INFO
appender.SCON.layout=org.apache.log4cpp.PatternLayout
appender.SCON.layout.ConversionPattern=%m%n


# --- MAIN ---
appender.MAIN=org.apache.log4cpp.RollingFileAppender
appender.MAIN.fileName=/home/admin/uc/logs/MainAccess.log
appender.MAIN.maxFileSize=1000000000
appender.MAIN.maxBackupIndex=10
appender.MAIN.backupPattern=%Y-%m-%d
appender.MAIN.layout=org.apache.log4cpp.PatternLayout
appender.MAIN.layout.ConversionPattern=%d{%Y-%m-%d %H:%M:%S} [%p]: %m%n


# --- uc ---
appender.uc=org.apache.log4cpp.RollingFileAppender
appender.uc.fileName=/home/admin/uc/logs/uc.log
appender.uc.maxFileSize=500000000
appender.uc.maxBackupIndex=10
appender.uc.backupPattern=%Y-%m-%d
appender.uc.layout=org.apache.log4cpp.PatternLayout
appender.uc.layout.ConversionPattern=%d{%Y-%m-%d %H:%M:%S} [%p]: %m%n


# --- uc_access ---
appender.uc_access=org.apache.log4cpp.RollingFileAppender
appender.uc_access.fileName=/home/admin/uc/logs/uc_access.log
appender.uc_access.maxFileSize=500000000
appender.uc_access.maxBackupIndex=20
appender.uc_access.backupPattern=.%Y-%m-%d-%H
appender.uc_access.layout=org.apache.log4cpp.PatternLayout
appender.uc_access.layout.ConversionPattern=%m%n


# --- uc_access_time ---
appender.uc_access_time=org.apache.log4cpp.TimeRollingFileAppender
appender.uc_access_time.fileName=/home/admin/uc/logs/uc_access.log
appender.uc_access_time.maxFileAge=3600
appender.uc_access_time.backupPattern=.%Y-%m-%d-%H
appender.uc_access_time.layout=org.apache.log4cpp.PatternLayout
appender.uc_access_time.layout.ConversionPattern=%m%n


