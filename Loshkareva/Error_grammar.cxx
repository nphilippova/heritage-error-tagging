#encoding "utf-8"    
#GRAMMAR_ROOT S
    
 // AdjNounAgr
 // Очень многий (и|, красивий)любовниц
S -> Adv* interp (AgrAdjNoun.Adv1::not_norm)  Adj<~gnc-agr[1]>+ interp (AgrAdjNoun.Adj1::not_norm) Noun<~gnc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv* interp (AgrAdjNoun.Adv1::not_norm) Adj<~gn-agr[1]>+ interp (AgrAdjNoun.Adj1::not_norm)  Noun<~gn-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv* interp (AgrAdjNoun.Adv1::not_norm) Adj<~gc-agr[1]>+ interp (AgrAdjNoun.Adj1::not_norm)  Noun<~gc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) Adj<~nc-agr[1]>+  interp (AgrAdjNoun.Adj1::not_norm)  Noun<~nc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);

S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) AdjP<~c-agr[1]> interp (AgrAdjNoun.Adj1::not_norm) Noun<~c-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) AdjP<~gc-agr[1]> interp (AgrAdjNoun.Adj1::not_norm) Noun<~gc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) AdjP<~gn-agr[1]> interp (AgrAdjNoun.Adj1::not_norm) Noun<~gn-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) AdjP<~nc-agr[1]> interp (AgrAdjNoun.Adj1::not_norm) Noun<~nc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);

S -> Adv*  interp (AgrAdjNoun.Adv1::not_norm) AdjP<~gnc-agr[1]> interp (AgrAdjNoun.Adj1::not_norm)  Noun<~gnc-agr[1]> interp (AgrAdjNoun.Noun1::not_norm);
AdjP ->  Adj<gnc-agr[1]> interp (AgrAdjNoun.Adj1::not_norm)  (Comma) Adj<gnc-agr[1]> interp (AgrAdjNoun.Adj2::not_norm)|Adj interp (AgrAdjNoun.Adj1::not_norm);
AdjP ->  Adj<gnc-agr[1]> interp (AgrAdjNoun.Adj1::not_norm)  (SimConjAnd) Adj<gnc-agr[1]> interp (AgrAdjNoun.Adj2::not_norm)|Adj interp (AgrAdjNoun.Adj1::not_norm);

// друг - очень простой вещь.
S -> Noun<GU =[m,sg]> interp (AgrDef.Def1::not_norm) Def DefW interp(AgrDef.Def2::not_norm);
Def -> Hyphen|"это"| Hyphen "это";
DefW -> Adv* Adj<~gnc-agr[1]>  Noun<~gnc-agr[1]>;

//что такой друг?
S ->  "что" interp(AgrDef.Def1::not_norm) Word<GU=[APRO,sg,m,nom]>  interp (AgrDef.Def2::not_norm) Noun<GU =[m,sg]> interp (AgrDef.Def3::not_norm) Punct|EOSent;
//S ->  FirstW interp (AgrDef.Def1::not_norm)  Word<GU=[APRO,sg,m,nom]>  interp (AgrDef.Def2::not_norm) Noun<GU =[m,sg]> interp (AgrDef.Def3::not_norm) Punct|EOSent;
//FirstW -> Word <GU =[SPRO,inan,nom]> | Word <GU =[CONJ]>;
//W2 -> "такой"|"такая"|"такие";

//ДРУЗЬЯ которую зовут катя.
S -> Noun <~gn-agr[1]> interp (AgrNounNoun.N1::not_norm) "которую|ого|ых" interp (AgrNounNoun.A1::not_norm) Verb interp (AgrNounNoun.V1::not_norm) Word<~gn-agr[1]> interp (AgrNounNoun.N2::not_norm);

//"Фараон забыла ради нее свой гарем и везде ее водил."
S -> Noun <~sp-agr[1],rt> interp (AgrSP.N::not_norm)   Verb <~sp-agr[1]> interp (AgrSP.V1::not_norm)   Word*  SimConjAnd interp (AgrSP.Conj)  Word <GU = ~[SPRO]>*  Verb <~sp-agr[1]> interp (AgrSP.V2::not_norm)  ;
S -> Noun <~sp-agr[1],sp-agr[2],rt> interp (AgrSP.N::not_norm)   Verb <~sp-agr[1]> interp (AgrSP.V1::not_norm)  SimConjAnd interp (AgrSP.Conj)  Word <GU = ~[SPRO]>*  Verb <sp-agr[2]> interp (AgrSP.V2::not_norm)  ;
S -> Noun <sp-agr[1],~sp-agr[2],rt> interp (AgrSP.N::not_norm)   Verb <sp-agr[1]> interp (AgrSP.V1::not_norm)   Word*  SimConjAnd interp (AgrSP.Conj)  Word <GU = ~[SPRO]>*  Verb <~sp-agr[2]> interp (AgrSP.V2::not_norm)  ;

// "Очень люблю впечатления людей– как они видит или воспринимают что либо."
S ->  Word <~sp-agr[1],rt,sp-agr[2]> interp (AgrSP.N::not_norm)  Verb <~sp-agr[1]> interp (AgrSP.V1::not_norm) "или" interp (AgrSP.Conj)  Verb<sp-agr[2]> interp (Agreement.D::not_norm) Word*;
//NP -> Noun Noun <GU=[gen]>;


// "Новый подруга|друзья Антона улыбнулся" WRONG
S -> Adj <~gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,~gnc-agr[3], ~sp-agr[2]> interp (Agreement.B::not_norm) Word <GU=~[gen]> interp (Agreement.C::not_norm)  Verb<~sp-agr[2]> interp (Agreement.D::not_norm)  ;
S -> Adj <~gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,~gnc-agr[3], ~sp-agr[2]> interp (Agreement.B::not_norm) Word <GU=[gen]> interp (Agreement.C::not_norm)  Verb<~sp-agr[2] > interp (Agreement.D::not_norm) ;
S -> Adj <gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,gnc-agr[3],~sp-agr[2]> interp (Agreement.B::not_norm) Word <GU=[gen]> interp (Agreement.C::not_norm)  Verb<~sp-agr[2]> interp (Agreement.D::not_norm);
S -> Adj <gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,gnc-agr[3],~sp-agr[2]> interp (Agreement.B)Word <GU=~[gen]> interp (Agreement.C::not_norm) Verb<~sp-agr[2]> interp (Agreement.D::not_norm);

S -> Adj <~gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,~gnc-agr[3], sp-agr[2]> interp (Agreement.B::not_norm) Word <GU=[gen]> interp (Agreement.C::not_norm)  Verb<sp-agr[2] > interp (Agreement.D::not_norm) ;
S -> Adj <~gnc-agr[3]>+ interp (Agreement.A::not_norm)  Word <rt,~gnc-agr[3], sp-agr[2]> interp (Agreement.B)Word <GU=~[gen]> interp (Agreement.C::not_norm) Verb<sp-agr[2] > interp (Agreement.D::not_norm) ;
// МОЙ друг меня любил  = попадает в выдачу! Убрать


// "Андрей и я любят..." WRONG
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],c-agr[1],~sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <gram ="ipf,tran,inpraes,pl,indic,3p", ~sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],c-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],~c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],~c-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],~nc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],~nc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],~gc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],~gc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <GU=[NUM]|[S]|[SPRO]|[persn],~gnc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<GU=[NUM]|[S]|[SPRO],~gnc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);

S -> Word <c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<c-agr[1],~sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <gram ="ipf,tran,inpraes,pl,indic,3p", ~sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<c-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <~c-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<~c-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);

S -> Word <~nc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<~nc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <~gc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<~gc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb<rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);
S -> Word <~gnc-agr[1]> interp (AgrNConjNV.W1::not_norm) SimConjAnd interp (AgrNConjNV.C::not_norm) Word<~gnc-agr[1],sp-agr[2]> interp (AgrNConjNV.W2::not_norm) Verb <rt, sp-agr[2]> interp (AgrNConjNV.V::not_norm);

// моя семья часто переежали.
S -> Word <GU=[APRO]|[A] ,gnc-agr[1]> interp (AgrAdjNV.Adj::not_norm) Word<GU=[S]|[SPRO]|[persn],gnc-agr[1],rt,~sp-agr[2]> interp (AgrAdjNV.N::not_norm) Adv interp (AgrAdjNV.Adv::not_norm) Verb<~sp-agr[2]> interp (AgrAdjNV.V::not_norm);
S -> Word <GU=[APRO]|[A] ,gnc-agr[1]> interp (AgrAdjNV.Adj::not_norm) Word<GU=[S]|[SPRO]|[persn],gnc-agr[1],rt,~sp-agr[2]> interp (AgrAdjNV.N::not_norm) Verb<~sp-agr[2]> interp (AgrAdjNV.V::not_norm);

// По-английский
S -> Word<wfm=/по-.*[цс]кий/> interp (Error.First::not_norm);
S -> Word<wfm=/.о-.*[цс]кии/> interp (Error.First::not_norm);
S -> Word<wfm=/ПО-.*[ЦС]КИ[ИЙ]/> interp (Error.First::not_norm);
S -> Word<wfm=/[^ПО]-.*[ЦС]КИ/> interp (Error.First::not_norm);



