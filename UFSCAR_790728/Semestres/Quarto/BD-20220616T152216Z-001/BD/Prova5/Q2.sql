/*
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
*/

--Questão 2
INSERT INTO Estudante (RA, nomeEstudante, endCep,sexo, dtNascEstudante, loginEmailEstudante)  
VALUES ( '84273', 'Jaqueline Gusmão', '50090','F', TO_DATE('1999-08-16','YYYY-MM-DD'), 'jaq');

INSERT INTO curso (Sigla, nomeCurso) VALUES  
('MED', 'Medicina');

INSERT INTO matricula  (RA, Sigla, dtMatricula, status)  
VALUES   ((SELECT RA FROM estudante WHERE nomeEstudante = ('Jaqueline Gusmão')), 'MED', TO_DATE('2010-12-09','YYYY-MM-DD'), 'ATIVO');