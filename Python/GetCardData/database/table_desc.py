tables = {}
tables["student"] = (
    "CREATE TABLE `student` ("
    "`stu_num` char(10) NOT NULL,"
    "`stu_name` varchar(10) NOT NULL,"
    "PRIMARY KEY (`stu_num`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)

tables["zc"] = (
    "CREATE TABLE `zc` ("
    "`id` int(6) NOT NULL AUTO_INCREMENT,"
    "`stu_num` char(10) NOT NULL,"
    "`date` date NOT NULL,"
    "`time` varchar(20),"
    "`is_valid` char(4) NOT NULL,"
    "PRIMARY KEY(`id`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)

tables["jlb"] = (
    "CREATE TABLE `jlb` ("
    "`id` int(6) NOT NULL AUTO_INCREMENT,"
    "`stu_num` char(10) NOT NULL,"
    "`date` date NOT NULL,"
    "`time` varchar(20),"
    "`is_valid` char(4) NOT NULL,"
    "PRIMARY KEY(`id`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)

tables["zzxx"] = (
    "CREATE TABLE `zzxx` ("
    "`id` int(6) NOT NULL AUTO_INCREMENT,"
    "`stu_num` char(10) NOT NULL,"
    "`date` date NOT NULL,"
    "`time` varchar(20),"
    "`is_valid` char(4) NOT NULL,"
    "PRIMARY KEY(`id`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)

tables["sttz"] = (
    "CREATE TABLE `sttz` ("
    "`id` int(6) NOT NULL AUTO_INCREMENT,"
    "`stu_num` char(10) NOT NULL,"
    "`date` date NOT NULL,"
    "`time` varchar(20),"
    "`is_valid` char(4) NOT NULL,"
    "PRIMARY KEY(`id`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)

tables["overview"] = (
    "CREATE TABLE `overview` ("
    "`stu_num` char(10) NOT NULL,"
    "`zc_valid` tinyint(1) NOT NULL,"
    "`jlb_valid` tinyint(1) NOT NULL,"
    "`sttz_valid` tinyint(1) NOT NULL,"
    "`zzxx_valid` tinyint(1) NOT NULL,"
    "`zc_not_valid` tinyint(1) NOT NULL,"
    "`jlb_not_valid` tinyint(1) NOT NULL,"
    "`sttz_not_valid` tinyint(1) NOT NULL,"
    "`zzxx_not_valid` tinyint(1) NOT NULL,"
    "PRIMARY KEY(`stu_num`)"
    ") ENGINE = InnoDB DEFAULT CHARSET=utf8"
)