/*
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
*/

--Questão 1
CREATE TABLE Estudante(  
 
RA char(10) not null,  
 
nomeEstudante varchar(40) not null,  
 
endRua varchar(30),  
 
endNro char(5),  
 
endBairro varchar(30),  
 
endCEP char(8),  
 
endCidade varchar(30) default 'São Carlos',  
 
sexo char(1),  
 
dtNascEstudante date not null,  
 
loginEmailEstudante varchar(30) not null,  
 
dominioEmailEstudante varchar(30) default '@estudante.ufscar.br',  
 
foneDDD char(3),  
 
fonePrefixo char(4),  
 
foneNumero char(10), 
 
  
 
CONSTRAINT Estudante_PK primary key(RA) 
 
);

CREATE TABLE curso(  
	Sigla VARCHAR(6),  
	nomeCurso VARCHAR(40),  
	CONSTRAINT curso_PK PRIMARY KEY (Sigla)  
);

CREATE TABLE matricula(  
 
	RA char(10),  
	Sigla VARCHAR(6),  
	dtMatricula DATE,  
	status VARCHAR(10) DEFAULT 'ATIVO',  
	CONSTRAINT matricula_ra_fk FOREIGN KEY (RA)  
		REFERENCES estudante (RA),  
	  
	CONSTRAINT matricula_sigla_fk FOREIGN KEY (Sigla)  
		REFERENCES curso (Sigla),  
	  
	CONSTRAINT matricula_pk PRIMARY KEY (RA,dtMatricula)  
);


