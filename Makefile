# *****************************************************************************************
# Project:              Networks
# Subtree:              /home1/hema/Networks/src
# Filename:             Makefile for Networks
# Programmer:           Hema A Murthy
# Host System:          Linux
# Date Created:         08/March/2008
# Project:              Client and  Server
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./src/include/
CFLAGS = -g -m32 -c -I$(INCDIR)
CC = gcc

all :	$(BINDIR)/Server $(BINDIR)/Client $(BINDIR)/Test 

$(BINDIR)/Test : $(SRCDIR)/Test.c
	$(CC) -m32 -g -o $(BINDIR)/Test \
	-I$(INCDIR)	$(SRCDIR)/Test.c $(OBJDIR)/Huffman.o

$(BINDIR)/Server : $(OBJDIR)/Server.o \
	$(OBJDIR)/DgEcho.o 
	$(CC) -m32 -g -o $(BINDIR)/Server \
	$(OBJDIR)/Server.o \
	$(OBJDIR)/DgEcho.o \
	-I$(INCDIR)	

$(BINDIR)/Client : $(OBJDIR)/Client.o \
	$(OBJDIR)/DgClient.o $(OBJDIR)/Huffman.o $(OBJDIR)/Entropy.o $(OBJDIR)/SourceCoder.o $(OBJDIR)/ChannelCoder.o
	$(CC) -m32 -g -o $(BINDIR)/Client  \
	$(OBJDIR)/Client.o \
	$(OBJDIR)/DgClient.o \
	$(OBJDIR)/Huffman.o \
	$(OBJDIR)/Entropy.o \
	$(OBJDIR)/SourceCoder.o \
	$(OBJDIR)/ChannelCoder.o \
	-I$(INCDIR)

$(OBJDIR)/Server.o : $(SRCDIR)/Server.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/Server.o $(SRCDIR)/Server.c 

$(OBJDIR)/DgEcho.o : $(SRCDIR)/DgEcho.c 
	$(CC) $(CFLAGS) -o $(OBJDIR)/DgEcho.o $(SRCDIR)/DgEcho.c 

$(OBJDIR)/Client.o : $(SRCDIR)/Client.c 
	$(CC) $(CFLAGS) -o $(OBJDIR)/Client.o $(SRCDIR)/Client.c 

$(OBJDIR)/DgClient.o : $(SRCDIR)/DgClient.c 
	$(CC) $(CFLAGS) -o $(OBJDIR)/DgClient.o $(SRCDIR)/DgClient.c

$(OBJDIR)/Huffman.o : $(SRCDIR)/Huffman.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/Huffman.o $(SRCDIR)/Huffman.c

$(OBJDIR)/Entropy.o : $(SRCDIR)/Entropy.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/Entropy.o $(SRCDIR)/Entropy.c

$(OBJDIR)/ChannelCoder.o : $(SRCDIR)/ChannelCoder.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/ChannelCoder.o $(SRCDIR)/ChannelCoder.c

$(OBJDIR)/SourceCoder.o : $(SRCDIR)/SourceCoder.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/SourceCoder.o $(SRCDIR)/SourceCoder.c



clean: 
	rm -fr $(BINDIR)/Server $(BINDIR)/Client $(OBJDIR)/Server.o \
	$(OBJDIR)/DgEcho.o $(OBJDIR)/Client.o $(OBJDIR)/DgClient.o \
    $(OBJDIR)/Huffman.o $(OBJDIR)/Entropy.o $(OBJDIR)/SourceCoder.o \
	$(OBJDIR)/ChannelCoder.o $(BINDIR)/Test
	


