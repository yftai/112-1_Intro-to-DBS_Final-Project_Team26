create table apps(
    id varchar(40) NOT NULL,
    url text NOT NULL,
    title varchar(255) NOT NULL,
    developer varchar(255) NOT NULL,
    developer_link text NOT NULL,
    icon text NOT NULL,
    rating float(2, 1) default 0.0 NOT NULL,
    reviews_count int default 0 NOT NULL,
    description_raw text NOT NULL,
    description text NOT NULL,
    tagline text NOT NULL,
    pricing_hint text NOT NULL,
    last_mod date NOT NULL,
    primary key (id)
);

create table apps_categories(
    app_id varchar(40) NOT NULL,
    category_id varchar(40) NOT NULL,
    primary key (app_id, category_id),
    foreign key (app_id) references apps(id)
);

create table categories(
    id varchar(40) NOT NULL,
    title varchar(40) NOT NULL,
    primary key (id)
);

create table key_benefits(
    app_id varchar(40) NOT NULL,
    title varchar(255) NOT NULL,
    description text NOT NULL,
	counter int NOT NULL AUTO_INCREMENT,
    primary key (counter)
);

create table pricing_plan_features(
    app_id varchar(40) NOT NULL,
    pricing_plan_id varchar(40) NOT NULL,
    feature varchar(255) NOT NULL,
    counter int NOT NULL AUTO_INCREMENT,
    primary key (counter)
);

create table pricing_plans(
    id varchar(40) NOT NULL,
    app_id varchar(40) NOT NULL,
    title varchar(255) NULL,
    price varchar(255) NOT NULL,
    counter int NOT NULL AUTO_INCREMENT,
    primary key (counter)
);

create table reviews(
    app_id varchar(40) NOT NULL,
    author varchar(255) NULL,
    rating tinyint default 0 NOT NULL,
    posted_at varchar(40) NOT NULL,
    body text NULL,
    helpful_count int NOT NULL,
    developer_reply text NULL,
    developer_reply_posted_at varchar(40) NULL
);

create table users(
    name varchar(40) NOT NULL,
    id varchar(40) NOT NULL,
    password varchar(40) NOT NULL,
    counter int NOT NULL AUTO_INCREMENT,
    primary key (counter)
);

load data local infile './apps.csv'
into table apps
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './apps_categories.csv'
into table apps_categories
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './categories.csv'
into table categories
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './key_benefits.csv'
into table key_benefits
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './pricing_plan_features.csv'
into table pricing_plan_features
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './pricing_plans.csv'
into table pricing_plans
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './reviews.csv'
into table reviews
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;

load data local infile './users.csv'
into table users
fields terminated by ','
enclosed by '"'
lines terminated by '\n'
ignore 1 lines;