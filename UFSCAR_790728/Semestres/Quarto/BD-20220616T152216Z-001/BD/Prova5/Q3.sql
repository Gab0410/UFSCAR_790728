/*
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
*/

--Questão 3
INSERT INTO Estudante (RA, nomeEstudante, endCep,sexo,dtNascEstudante, loginEmailEstudante)  
VALUES ('790728' , 'André de Paula', '13422','M', TO_DATE('2005-01-13','YYYY-MM-DD'), 'andre');

INSERT INTO matricula  (RA, Sigla, dtMatricula, status)  
VALUES  ((SELECT RA FROM estudante WHERE nomeEstudante = ('André de Paula')), 'MED', TO_DATE('2020-08-10','YYYY-MM-DD'), 'ATIVO');