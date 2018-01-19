-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Nov 16, 2017 at 01:58 PM
-- Server version: 5.7.19-0ubuntu0.17.04.1
-- PHP Version: 7.0.18-0ubuntu0.17.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kdac`
--

-- --------------------------------------------------------

--
-- Table structure for table `BookTable`
--

CREATE TABLE `BookTable` (
  `book_id` int(5) NOT NULL,
  `subject_name` varchar(50) NOT NULL,
  `book_name` varchar(50) NOT NULL,
  `author_name` varchar(50) NOT NULL,
  `price` float(10,2) NOT NULL,
  `publish_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `BookTable`
--

INSERT INTO `BookTable` (`book_id`, `subject_name`, `book_name`, `author_name`, `price`, `publish_date`) VALUES
(1001, 'C', 'The C Programming Language', 'Dennis Ritchie', 209.00, '1978-01-01'),
(1002, 'C', 'Let Us C', 'Yashavant Kanetkar', 279.00, '2016-07-13'),
(1003, 'C', 'C: The Complete Reference', 'Herbert Schildt', 675.00, '2017-07-01'),
(1004, 'C', 'Expert C Programming', 'Peter van der Linden', 2453.00, '1994-06-24'),
(1005, 'C', 'C How To Program', 'Paul J. Deitel', 11262.00, '2015-02-26'),
(1006, 'C++', 'The C++ Programming Language', 'Bjarne Stroustrup', 4710.00, '2003-05-09'),
(1007, 'C++', 'C++ Primer Plus', 'Stephen Prata', 2030.60, '2004-11-23'),
(1008, 'C++', 'C++ How to Program', 'Harvey Deitel and Paul Deitel', 11262.10, '2016-02-29'),
(1009, 'C++', 'Inside the C++ Object Model', 'Stanley B. Lippman', 5548.75, '1996-05-03'),
(1010, 'Operating System', ' The Design of the UNIX Operating System', ' Maurice J. Bach', 350.00, '1988-01-01');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `BookTable`
--
ALTER TABLE `BookTable`
  ADD PRIMARY KEY (`book_id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
