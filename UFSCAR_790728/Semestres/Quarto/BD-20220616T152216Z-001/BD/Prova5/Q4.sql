/*
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
*/

--Questão 4
SELECT nomeEstudante,loginEmailEstudante 
FROM curso,estudante JOIN matricula ON Estudante.RA = matricula.RA 
WHERE curso.nomeCurso = 'Medicina' AND matricula.status = 'ATIVO' AND estudante.sexo = 'F';
