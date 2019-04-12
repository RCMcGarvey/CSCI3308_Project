--
-- PostgreSQL database dump
--

-- Dumped from database version 10.7 (Ubuntu 10.7-0ubuntu0.18.04.1)
-- Dumped by pg_dump version 10.7 (Ubuntu 10.7-0ubuntu0.18.04.1)

-- Started on 2019-04-11 21:03:16 MDT

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 4 (class 2615 OID 16387)
-- Name: proj_schema; Type: SCHEMA; Schema: -; Owner: csci3308_proj
--

CREATE SCHEMA proj_schema;


ALTER SCHEMA proj_schema OWNER TO csci3308_proj;

--
-- TOC entry 1 (class 3079 OID 13039)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2970 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 204 (class 1259 OID 16530)
-- Name: Characters; Type: TABLE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE TABLE proj_schema."Characters" (
    char_id integer NOT NULL,
    name text NOT NULL,
    stats text NOT NULL,
    inventory integer NOT NULL,
    creator integer,
    level integer NOT NULL
);


ALTER TABLE proj_schema."Characters" OWNER TO csci3308_proj;

--
-- TOC entry 2971 (class 0 OID 0)
-- Dependencies: 204
-- Name: TABLE "Characters"; Type: COMMENT; Schema: proj_schema; Owner: csci3308_proj
--

COMMENT ON TABLE proj_schema."Characters" IS 'Stores all the characters';


--
-- TOC entry 205 (class 1259 OID 16533)
-- Name: Characters_char_id_seq; Type: SEQUENCE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE SEQUENCE proj_schema."Characters_char_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE proj_schema."Characters_char_id_seq" OWNER TO csci3308_proj;

--
-- TOC entry 2972 (class 0 OID 0)
-- Dependencies: 205
-- Name: Characters_char_id_seq; Type: SEQUENCE OWNED BY; Schema: proj_schema; Owner: csci3308_proj
--

ALTER SEQUENCE proj_schema."Characters_char_id_seq" OWNED BY proj_schema."Characters".char_id;


--
-- TOC entry 198 (class 1259 OID 16416)
-- Name: Inventory; Type: TABLE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE TABLE proj_schema."Inventory" (
    inventory_id integer NOT NULL,
    items integer[]
);


ALTER TABLE proj_schema."Inventory" OWNER TO csci3308_proj;

--
-- TOC entry 203 (class 1259 OID 16485)
-- Name: Inventory_inventory_id_seq; Type: SEQUENCE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE SEQUENCE proj_schema."Inventory_inventory_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE proj_schema."Inventory_inventory_id_seq" OWNER TO csci3308_proj;

--
-- TOC entry 2973 (class 0 OID 0)
-- Dependencies: 203
-- Name: Inventory_inventory_id_seq; Type: SEQUENCE OWNED BY; Schema: proj_schema; Owner: csci3308_proj
--

ALTER SEQUENCE proj_schema."Inventory_inventory_id_seq" OWNED BY proj_schema."Inventory".inventory_id;


--
-- TOC entry 200 (class 1259 OID 16429)
-- Name: Items; Type: TABLE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE TABLE proj_schema."Items" (
    name text,
    item_desc text,
    item_id integer NOT NULL
);


ALTER TABLE proj_schema."Items" OWNER TO csci3308_proj;

--
-- TOC entry 2974 (class 0 OID 0)
-- Dependencies: 200
-- Name: TABLE "Items"; Type: COMMENT; Schema: proj_schema; Owner: csci3308_proj
--

COMMENT ON TABLE proj_schema."Items" IS 'Stores all possible items';


--
-- TOC entry 206 (class 1259 OID 16574)
-- Name: Items_item_id_seq; Type: SEQUENCE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE SEQUENCE proj_schema."Items_item_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE proj_schema."Items_item_id_seq" OWNER TO csci3308_proj;

--
-- TOC entry 2975 (class 0 OID 0)
-- Dependencies: 206
-- Name: Items_item_id_seq; Type: SEQUENCE OWNED BY; Schema: proj_schema; Owner: csci3308_proj
--

ALTER SEQUENCE proj_schema."Items_item_id_seq" OWNED BY proj_schema."Items".item_id;


--
-- TOC entry 199 (class 1259 OID 16421)
-- Name: Levels; Type: TABLE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE TABLE proj_schema."Levels" (
    level_desc text,
    level_id integer NOT NULL,
    items integer[]
);


ALTER TABLE proj_schema."Levels" OWNER TO csci3308_proj;

--
-- TOC entry 2976 (class 0 OID 0)
-- Dependencies: 199
-- Name: TABLE "Levels"; Type: COMMENT; Schema: proj_schema; Owner: csci3308_proj
--

COMMENT ON TABLE proj_schema."Levels" IS 'Stores all the levels';


--
-- TOC entry 202 (class 1259 OID 16461)
-- Name: Levels_level_id_seq; Type: SEQUENCE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE SEQUENCE proj_schema."Levels_level_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE proj_schema."Levels_level_id_seq" OWNER TO csci3308_proj;

--
-- TOC entry 2977 (class 0 OID 0)
-- Dependencies: 202
-- Name: Levels_level_id_seq; Type: SEQUENCE OWNED BY; Schema: proj_schema; Owner: csci3308_proj
--

ALTER SEQUENCE proj_schema."Levels_level_id_seq" OWNED BY proj_schema."Levels".level_id;


--
-- TOC entry 197 (class 1259 OID 16388)
-- Name: User; Type: TABLE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE TABLE proj_schema."User" (
    username text NOT NULL,
    usr_password text NOT NULL,
    user_id integer NOT NULL,
    characters integer[]
);


ALTER TABLE proj_schema."User" OWNER TO csci3308_proj;

--
-- TOC entry 201 (class 1259 OID 16452)
-- Name: User_user_id_seq; Type: SEQUENCE; Schema: proj_schema; Owner: csci3308_proj
--

CREATE SEQUENCE proj_schema."User_user_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE proj_schema."User_user_id_seq" OWNER TO csci3308_proj;

--
-- TOC entry 2978 (class 0 OID 0)
-- Dependencies: 201
-- Name: User_user_id_seq; Type: SEQUENCE OWNED BY; Schema: proj_schema; Owner: csci3308_proj
--

ALTER SEQUENCE proj_schema."User_user_id_seq" OWNED BY proj_schema."User".user_id;


--
-- TOC entry 2818 (class 2604 OID 16535)
-- Name: Characters char_id; Type: DEFAULT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Characters" ALTER COLUMN char_id SET DEFAULT nextval('proj_schema."Characters_char_id_seq"'::regclass);


--
-- TOC entry 2815 (class 2604 OID 16487)
-- Name: Inventory inventory_id; Type: DEFAULT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Inventory" ALTER COLUMN inventory_id SET DEFAULT nextval('proj_schema."Inventory_inventory_id_seq"'::regclass);


--
-- TOC entry 2817 (class 2604 OID 16576)
-- Name: Items item_id; Type: DEFAULT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Items" ALTER COLUMN item_id SET DEFAULT nextval('proj_schema."Items_item_id_seq"'::regclass);


--
-- TOC entry 2816 (class 2604 OID 16463)
-- Name: Levels level_id; Type: DEFAULT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Levels" ALTER COLUMN level_id SET DEFAULT nextval('proj_schema."Levels_level_id_seq"'::regclass);


--
-- TOC entry 2814 (class 2604 OID 16454)
-- Name: User user_id; Type: DEFAULT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."User" ALTER COLUMN user_id SET DEFAULT nextval('proj_schema."User_user_id_seq"'::regclass);


--
-- TOC entry 2959 (class 0 OID 16530)
-- Dependencies: 204
-- Data for Name: Characters; Type: TABLE DATA; Schema: proj_schema; Owner: csci3308_proj
--

COPY proj_schema."Characters" (char_id, name, stats, inventory, creator, level) FROM stdin;
\.


--
-- TOC entry 2953 (class 0 OID 16416)
-- Dependencies: 198
-- Data for Name: Inventory; Type: TABLE DATA; Schema: proj_schema; Owner: csci3308_proj
--

COPY proj_schema."Inventory" (inventory_id, items) FROM stdin;
\.


--
-- TOC entry 2955 (class 0 OID 16429)
-- Dependencies: 200
-- Data for Name: Items; Type: TABLE DATA; Schema: proj_schema; Owner: csci3308_proj
--

COPY proj_schema."Items" (name, item_desc, item_id) FROM stdin;
\.


--
-- TOC entry 2954 (class 0 OID 16421)
-- Dependencies: 199
-- Data for Name: Levels; Type: TABLE DATA; Schema: proj_schema; Owner: csci3308_proj
--

COPY proj_schema."Levels" (level_desc, level_id, items) FROM stdin;
\.


--
-- TOC entry 2952 (class 0 OID 16388)
-- Dependencies: 197
-- Data for Name: User; Type: TABLE DATA; Schema: proj_schema; Owner: csci3308_proj
--

COPY proj_schema."User" (username, usr_password, user_id, characters) FROM stdin;
aryan	pass	1	\N
\.


--
-- TOC entry 2979 (class 0 OID 0)
-- Dependencies: 205
-- Name: Characters_char_id_seq; Type: SEQUENCE SET; Schema: proj_schema; Owner: csci3308_proj
--

SELECT pg_catalog.setval('proj_schema."Characters_char_id_seq"', 1, false);


--
-- TOC entry 2980 (class 0 OID 0)
-- Dependencies: 203
-- Name: Inventory_inventory_id_seq; Type: SEQUENCE SET; Schema: proj_schema; Owner: csci3308_proj
--

SELECT pg_catalog.setval('proj_schema."Inventory_inventory_id_seq"', 1, false);


--
-- TOC entry 2981 (class 0 OID 0)
-- Dependencies: 206
-- Name: Items_item_id_seq; Type: SEQUENCE SET; Schema: proj_schema; Owner: csci3308_proj
--

SELECT pg_catalog.setval('proj_schema."Items_item_id_seq"', 1, false);


--
-- TOC entry 2982 (class 0 OID 0)
-- Dependencies: 202
-- Name: Levels_level_id_seq; Type: SEQUENCE SET; Schema: proj_schema; Owner: csci3308_proj
--

SELECT pg_catalog.setval('proj_schema."Levels_level_id_seq"', 1, false);


--
-- TOC entry 2983 (class 0 OID 0)
-- Dependencies: 201
-- Name: User_user_id_seq; Type: SEQUENCE SET; Schema: proj_schema; Owner: csci3308_proj
--

SELECT pg_catalog.setval('proj_schema."User_user_id_seq"', 1, false);


--
-- TOC entry 2828 (class 2606 OID 16540)
-- Name: Characters pk_characters; Type: CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Characters"
    ADD CONSTRAINT pk_characters PRIMARY KEY (char_id);


--
-- TOC entry 2822 (class 2606 OID 16493)
-- Name: Inventory pk_inventory; Type: CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Inventory"
    ADD CONSTRAINT pk_inventory PRIMARY KEY (inventory_id);


--
-- TOC entry 2826 (class 2606 OID 16584)
-- Name: Items pk_items; Type: CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Items"
    ADD CONSTRAINT pk_items PRIMARY KEY (item_id);


--
-- TOC entry 2824 (class 2606 OID 16473)
-- Name: Levels pk_levels; Type: CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Levels"
    ADD CONSTRAINT pk_levels PRIMARY KEY (level_id);


--
-- TOC entry 2820 (class 2606 OID 16471)
-- Name: User pk_user; Type: CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."User"
    ADD CONSTRAINT pk_user PRIMARY KEY (user_id);


--
-- TOC entry 2830 (class 2606 OID 16608)
-- Name: Characters Characters_creator_fkey; Type: FK CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Characters"
    ADD CONSTRAINT "Characters_creator_fkey" FOREIGN KEY (creator) REFERENCES proj_schema."User"(user_id) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- TOC entry 2829 (class 2606 OID 16603)
-- Name: Characters Characters_level_fkey; Type: FK CONSTRAINT; Schema: proj_schema; Owner: csci3308_proj
--

ALTER TABLE ONLY proj_schema."Characters"
    ADD CONSTRAINT "Characters_level_fkey" FOREIGN KEY (level) REFERENCES proj_schema."Levels"(level_id) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- TOC entry 2969 (class 0 OID 0)
-- Dependencies: 3
-- Name: SCHEMA public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
GRANT USAGE ON SCHEMA public TO PUBLIC;


-- Completed on 2019-04-11 21:03:16 MDT

--
-- PostgreSQL database dump complete
--

