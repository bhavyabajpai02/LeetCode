CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        Select salary  from ( Select Distinct salary,Dense_Rank() over(order by salary DESC) as rn from Employee) as t  where rn = N
  );
END