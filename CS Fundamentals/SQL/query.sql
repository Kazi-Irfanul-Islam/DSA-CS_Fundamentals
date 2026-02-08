-- FIND ALL EMPLOYEES ORDERED BY SALARIES
SELECT * FROM employee
ORDER BY salary DESC;

-- FIND ALL EMPLOYEES ORDERED BY SEX THEN NAME
SELECT * FROM employee
ORDER BY sex, first_name, last_name;

-- FIND FIRSTNAME AND LASTNAME OF ALL EMPLOYEE
SELECT first_name, last_name
FROM employee;

-- FIND THE FORENAMES AND SURNAMES OF ALL EMPLOYHEE
SELECT first_name AS forename, last_name AS surname
FROM employee;

-- FIND OUT ALL THE DIFFERENT GENDERS
SELECT DISTINCT branch_id
FROM employee;

-- FIND THE NUMBER OF EMPLOYEE
SELECT COUNT(emp_id)
FROM employee;

-- FIND THE NUMBER OF FEMALE EMPLOYEE BORN AFTER 1970
SELECT COUNT(emp_id) 
FROM employee
WHERE sex = 'F' AND birth_day > '1970-01-01';

-- FIND THE AVERAGE SALARY OF ALL EMPLOYEE
SELECT AVG(salary)
FROM employee
WHERE SEX = 'M';

-- FIND THE SUM OF ALL EMPLOYEES SALARY
SELECT SUM(salary)
FROM employee;

-- FIND OUT HOW MANY MALE AND FEMALE ARE THERE
SELECT COUNT(sex), sex
FROM employee
GROUP BY sex;

-- FIND THE TOTAL SALES OF EACH EMPLOTYEE
SELECT SUM(total_sales), emp_id
FROM works_with
GROUP BY emp_id;

-- FIND ANY CLIENT WHOA ARE IN LLC
SELECT * FROM client
WHERE client_name LIKE '%LLC';

-- FIND ANY BRANCH SUPPLIERS WHO ARE IN THE LABEL BUSINESS
SELECT * FROM branch_supplier
WHERE supplier_name LIKE '%Label%';

-- FIND ANY EMPLOYEE BORN IN OCTOBER
SELECT * FROM employee
WHERE birth_day LIKE '____-10%';

-- FIND ANY CLIENT WHO ARE SCHOOLS
SELECT * FROM client
WHERE client_name LIKE '%school%';

-------------------- JOIN ---------------------

-- FIND ALL BRANCHES AND NAME OF THEIR MANAGERS
SELECT employee.emp_id, employee.first_name, branch.branch_name
FROM employee
JOIN branch
ON employee.emp_id = branch.mgr_id;

----------------------------------------------

-- FIND THE NAME OF ALL EMPLOYEES WHO HAVE SOLD OVER 30000 TO A SINGLE CLIENT
SELECT  employee.first_name, employee.last_name
FROM employee
WHERE employee.emp_id IN (
    SELECT works_with.emp_id
    FROM works_with
    WHERE works_with.total_sales > 30000
);

-- FIND ALL THE CLIENT WHO ARE HANDLED BY THE BRANCH THAT MICHEAL SCOTT MANAGES 
-- ASSUME THAT YOU KNOW THE MICEALS ID WHICH IS 102
SELECT client.client_name
FROM client
WHERE client.branch_id = (
    SELECT branch.branch_id
    FROM branch 
    WHERE branch.mgr_id = 102
    LIMIT 1
);


DESCRIBE employee;
SELECT * FROM works_with;