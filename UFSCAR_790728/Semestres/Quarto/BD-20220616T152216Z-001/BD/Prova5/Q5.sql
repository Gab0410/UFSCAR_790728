/*
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
*/

--Questão 5
UPDATE matricula  
    SET matricula.status = 'CONCLUIDO'  
WHERE matricula.RA in (SELECT estudante.RA FROM  estudante WHERE nomeEstudante = 'Jaqueline Gusmão');

SELECT nomeEstudante,loginEmailEstudante 
FROM curso,estudante JOIN matricula ON Estudante.RA = matricula.RA 
WHERE curso.nomeCurso = 'Medicina' AND matricula.status = 'ATIVO' AND estudante.sexo = 'F';



