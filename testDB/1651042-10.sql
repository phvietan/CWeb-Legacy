-- MSSV: 1651042
-- Name: Pham Viet An

-- Task 1
CREATE DATABASE University;

GO
USE University;

-- Task 2
CREATE TABLE Students (
    StudentId VARCHAR(7),
    FirstName VARCHAR(25),
    LastName VARCHAR(25),
    Age INT,
    Class VARCHAR(10)
);
CREATE TABLE Courses (
    CourseCode VARCHAR(10),
    CourseName VARCHAR(255),
    CourseYear INT,
    Semester INT,
    Lecturer VARCHAR(64)
);

-- Task 3
INSERT INTO Students
VALUES ('1651042', 'An', 'Pham', 20, '16CTT'),
('1651044', 'Duc', 'Le', 20, '16CTT'),
('1851042', 'Nguyen', 'Tran', 18, '18CTT'),
('1651065', 'Bao', 'Nguyen', 20, '16CTT'),
('1651062', 'Phat', 'Tran', 20, '16CTT'),
('1651060', 'Huy', 'Bui', 20, '16CTT'),
('1651059', 'Hoang', 'Chung', 20, '16CTT'),
('1551059', 'Quan', 'Pham', 21, '15CTT'),
('1651080', 'Adam', 'Levine', 20, '16CTT'),
('1651002', 'An', 'Pham', 20, '16CTT'),
('1651003', 'Nghi', 'Pham', 20, '16CTT'),
('1651004', 'Ngan', 'Thai', 20, '16CTT'),
('1651040', 'Minh', 'Nguyen', 20, '16CTT'),
('1751042', 'Huy', 'Le', 19, '17CTT'),
('1751044', 'Thuc', 'Vo', 19, '17CTT'),
('1751050', 'Mai', 'Tran', 19, '17CLC'),
('1751051', 'Ronaldo', 'Zuckerberg', 19, '17CNTN'),
('1751002', 'Minh', 'Ho', 19, '17CTT'),
('1751020', 'Minh', 'Nguyen', 19, '17CTT'),
('1751022', 'Nam', 'Nguyen', 19, '17CTT'),
('1851000', 'Nam', 'Le', 18, '18CTT'),
('1851001', 'Thao', 'Nguyen', 18, '18CLC'),
('1851020', 'Chau', 'Tran', 18, '18CTT'),
('1851021', 'Lai', 'Thanh', 18, '18CTT'),
('1851022', 'Viet', 'Cong', 18, '18CTT'),
('1851023', 'Gogi', 'House', 18, '18CLC'),
('1851024', 'Dang', 'Hai', 18, '18CLC'),
('1851060', 'Bich', 'Tran', 18, '18CNTN'),
('1851061', 'Ti', 'Pham', 18, '18CNTN'),
('1551022', 'Thang', 'Tran', 21, '15CTT'),
('1552011', 'Khoi', 'Dinh', 21, '15CLC'),
('1742001', 'Bao', 'Hoang', 19, '17CTT'),
('1650000', 'Messi', 'Best', 20, '16CTT'),
('1650001', 'Vuong', 'Lam', 20, '16CNTN'),
('1650002', 'Goku', 'Son', 20, '16CNTN'),
('1650003', 'Power', 'Puff', 20, '16CNTN'),
('1650004', 'Lam', 'Le', 20, '16CLC'),
('1650005', 'Ragnarok', 'Online', 20, '16CTT'),
('1650006', 'Mai', 'Minh', 20, '16CTT'),
('1851111', 'Thao', 'Minh', 18, '18CLC');

INSERT INTO Courses
VALUES ('CS202', 'Programming System', 2017, 1, 'Dinh Ba Tien'),
('CS201', 'Computer Systems Programming II', 2017, 1, 'Dinh Dien'),
('MTH253', 'Calculus III', 2017, 3, 'Nguyen Huu Anh'),
('MTH261', 'Linear Algebra', 2018, 3, 'Nguyen Huu Anh'),
('CS386', 'Introduction to Database Systems', 2018, 3, 'Le Thi Nhan');

-- Task 4
SELECT * FROM Students;

-- Task 5
DELETE FROM Students WHERE StudentId='1651065';
DELETE FROM Courses WHERE CourseCode='CS201';

-- Task 6
DROP TABLE Students;
DROP TABLE Courses;

-- Task 7
ALTER DATABASE University SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
-- Select master database
USE master;
-- Remove database
DROP DATABASE University;