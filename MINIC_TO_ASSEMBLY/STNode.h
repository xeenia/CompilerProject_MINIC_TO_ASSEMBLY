#pragma once
// δημιουργούμε έναν τύπο enumeration type που κάθε μέλος του είναι ένας ξεχωριστός ακέραιος κωδικός για κάθε τύπο κόμβου που θέλουμε να δημιουργήσουμε στο συντακτικό δένδρο
#include <string>
#include <list>
#include <fstream>
using namespace std;
typedef enum nodeType {
	NT_COMPILEUNIT, NT_STATEMENTS, NT_STATEMENT,    //σε κάθε κωδικό δίνουμε αντιπροσωπευτικό όνομα με τον τύπο του κόμβου που αναπαριστά στην γραμματική, τα ονόματα που δώσαμε έχουν προκύψει από την γραμματική της απλής αριθμομηχανής πχ CompileUnit, statement, expression '+' expression κτλ 
	NT_EXPRESSION_NUMBER, NT_EXPRESSION_IDENTIFIER,
	NT_EXPRESSION_ADDITION, NT_EXPRESSION_SUBTRACTION,
	NT_EXPRESSION_MULTIPLICATION, NT_EXPRESSION_DIVISION,
	NT_EXPRESSION_MODULO, NT_EXPRESSION_NOT, NT_EXPRESSION_BIT_NOT,
	NT_EXPRESSION_BIGGER, NT_EXPRESSION_SMALLER,
	NT_EXPRESSION_BIT_AND, NT_EXPRESSION_BIT_OR, NT_EXPRESSION_BIT_XOR,
	NT_EXPRESSION_BIGGER_EQ, NT_EXPRESSION_SMALLER_EQ,
	NT_EXPRESSION_INC, NT_EXPRESSION_DCR,
	NT_EXPRESSION_EQ, NT_EXPRESSION_NOT_EQ,
	NT_EXPRESSION_LOGICAL_AND, NT_EXPRESSION_LOGICAL_OR,
	NT_EXPRESSION_ASSIGNMENT, NT_EXPRESSION_WHILE, NT_EXPRESSION_COMPOUND, NT_INSIDELIST, NT_IF_TELESTHS, NT_IF_STATEMENT,
	NT_FOR, NT_DO_WHILE, NT_PRINTF, NT_STRING
}NodeType; //αυτόν τον τύπο μπορούμε να τον χρησιμοποιήσουμε μέσα την κλάση STNode για να περιγράψουμε τον τύπο του κάθε κόμβου
class STNode { // τα πεδία της κλάσης αυτής περιέχουν πληροφορία την ίδια του συντακτικού δένδρου ? 3:00

public:
	ofstream* o;
	/*
		Μέθοδοι:

		1) Μέθοδοι που εκτελούν ανακτήσεις τιμών για τα πεδία που έχουμε ορίσει ως protected
		2) Modifaried? Methods που τροποποιούν τα δεδομένα της κλάσης καθώς και τον constructor & distructor
		3) Μέθοδο η οποία θα χρησιμοποιηθεί για την διάσχιση του δένδρου με στόχο την εκτύπωση του σε αρχείο εικόνας

	*/
	//--------------------------------------------------------------------------------------------------------------------------

	STNode(NodeType type); //constructor, βάζουμε ως παρ τύπου NodeType έτσι ώστε μέσα από τον κονστράκτορ να αρχικοποιηθεί το πεδίο m_nodetype που αναφέρεται στο τύπο του κόμβου
	virtual ~STNode(); //distructor, τον κάνουμε εικονικό ετσι ώστε το STNode να αποτελεί γονική κλάση...
	//οιπαρακάτω μέθοδοι μας επιστρέφουν δεδομένα της κλάσης
	NodeType GetNodeType(); //μας επιστρέφει τον τύπο του κόμβου
	string GetGraphvizLabel(); //μας επιστρέφει την ετικέτα του κόμβου
	STNode* GetChild(int index); //μας επιστρέφει κάποια από τα παιδιά του κόμβου; (ίσως δένδρο), στο ;index γράφουμε ποιο συγκεκριμένο παιδί θέλουμε
	STNode* GetParent(int index = 0); //δίνουμε στον index την τιμή 0 επειδή αν καλέσουμε την getparent χωρίς παράμετρο τότε να γίνει αυτόματα η τιμή της παρ. 0

	//modifier μέθοδο, αλλάζει την κλάση
	void AddChild(STNode* node); //στον τρέχοντα κόμβο
	//εικονική μέθοδο για την διάσχιση του δένρου με στόχο την εκτύπωση του με το εργαλείο Graphviz
	virtual void Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent);
	virtual void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg);
	void Get_FileP(ofstream* f);
	virtual int Visit_Eval();
protected:  // προστατευμένα πεδία και κλάσεις που μπορούν να προσπελαστούν μόνο από θυγατρικές κλάσεις της κλάσης STNode
	NodeType m_nodeType;
	string m_graphvizLabe1; //ετικέτα του κόμβου
	int m_serial; //μοναδικός σε κάθε κόμβο
	/*
		NODETYPE	SERIAL		SEMANTICVALUE(ΠΡΟΑΙΡΕΤΙΚΗ ΣΗΜΑΣΙΟΛΟΓΙΚΗ ΤΙΜΗ)

		px.
			COMPILEUNIT_0	NUMBER_25_2

		ΕΑΝ ΔΕΝ ΥΠΗΡΧΕ ΣΕΙΡΙΑΚΟΣ ΚΟΜΒΟΣ ΤΟΤΕ ΟΣΟΙ ΕΙΧΑΝ ΤΟΝ ΙΔΙΟ ΤΥΠΟ ΘΑ ΠΗΓΑΙΝΑΝΕ ΣΕ ΕΝΑΝ ΚΟΜΒΟ
	*/
	static int m_serialCounter; //για την απόδοση μοναδικου σειριακού αριθμού, κάθε φορά που δημιουργείται ένας κόμβος θα αναθέτει την τιμή του στην μεταβλητή m_serial και ταυτόχρονα θα αυξάνεται κατά 1 
	list<STNode*>* m_children;
	list<STNode*>* m_parents;

	static int c_if_st_flag, c_if_tel_flag, c_if_else_st_flag;
	static int c_while_flag, c_do_while_flag, c_for_flag;
};

extern STNode* g_root, *r_root;