#encoding "utf-8"    
#GRAMMAR_ROOT S

// " мне всегда была скучно"
S -> Word<GU=[SPRO,dat]|[S,dat]|[persn,dat]> interp(AgrSP.N::not_norm) (Word<gram="ADVPRO">) VP<rt> interp(AgrSP.V1::not_norm);
VP -> Word<wfm=/был[аи]/> Word<GU=[ADV]|[A,brev]>;

// многий ((и|,красивий)любовниц)
S -> AdjP<~gnc-agr[1]>  Noun<~gnc-agr[1],rt> interp(AgrAdjNV.N::not_norm) ;

AdjP -> Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj1::not_norm)  Word<gram="A,plen",kwtype=~Some_type>+ interp(AgrAdjNV.Adj2::not_norm) ;
AdjP ->  Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj1::not_norm)  Comma interp(AgrAdjNV.Conj::not_norm)  Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj2::not_norm);
AdjP ->  Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj1::not_norm)  SimConjAnd interp(AgrAdjNV.Conj::not_norm)  Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj2::not_norm);
AdjP -> Word<gram="A,plen",kwtype=~Some_type> interp(AgrAdjNV.Adj1::not_norm) ;


//ArgSP "Друг   слышал   и   нравится "
S ->  Noun<sp-agr[2]>  interp(AgrSP.N::not_norm) (Adv) VP<sp-agr[2]> ;
S ->  (Adv) VP<sp-agr[2]> Noun<sp-agr[2]>  interp(AgrSP.N::not_norm);
VP -> Verb<~gn-agr[1], gram=~"3p"> interp(AgrSP.V1::not_norm) (SimConjAnd)  Verb<~gn-agr[1]> interp(AgrSP.V2::not_norm);
VP -> Verb<~gn-agr[1],gram=~"3p"> interp(AgrSP.V1::not_norm) (Comma)  Verb<~gn-agr[1]> interp(AgrSP.V2::not_norm);
VP -> Verb<~gn-agr[1]> interp(AgrSP.V1::not_norm) (SimConjAnd)  Verb<~gn-agr[1],gram=~"3p"> interp(AgrSP.V2::not_norm);
VP -> Verb<~gn-agr[1]> interp(AgrSP.V1::not_norm) (Comma)  Verb<~gn-agr[1], gram=~"3p"> interp(AgrSP.V2::not_norm);

//Семья Ивана переехали
NP -> Noun<rt,gram=~"3p", gram="nom",kwtype=~Some_type>  Word<GU=[persn]|[S]>* ;
S -> U  NP<~sp-agr[1]> interp(AgrSP.N::not_norm) (Word<GU=[A]|[APRO]>)  Verb<~sp-agr[1],gram=~"3p"> interp(AgrSP.V1::not_norm) ; 

NP_3 -> Noun<rt,kwtype=~Some_type,gram="nom"> Word<GU=[persn]|[S]>*;
S -> U  NP_3<~sp-agr[1]> interp(AgrSP.N::not_norm) (Word<GU=[A]|[APRO]>)  Verb<~sp-agr[1]> interp(AgrSP.V1::not_norm) ; 
U -> Word<kwtype=~Prep> (Word<GU=~[A]|[APRO]|[SPRO]>);

// По-английский
S -> Word<wfm=/по-.*[цс]кий/> interp (Error.Morph::not_norm);
S -> Word<wfm=/.о-.*[цс]кии/> interp (Error.Morph::not_norm);
S -> Word<wfm=/ПО-.*[ЦС]КИ[ИЙ]/> interp (Error.Morph::not_norm);
S -> Word<wfm=/[^ПО]-.*[ЦС]КИ/> interp (Error.Morph:not_norm);
