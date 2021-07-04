#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>
#include <map>
#include <utility>
#include <vector>

#define p <<endl;
#define pp <<endl
#define sp cout pp pp p
#define linha cout pp <<"-----------------------------------------------------------------" p

using namespace std;

map<string,pair<double,int>>estoque;



struct opcao{

    double preco;
    int quantidade;
    string nome;
}cadastro,exclui,promocao,desconto,procura;


void cadastrar_desconto(){

    auto i=true;
    char opcao_promocao;
    cout<<"Entre com o desconto:";
    cin>>desconto.preco;

    for(auto it=estoque.begin();it!=estoque.end();it++)

        estoque.insert(pair<string,pair<double,int>>(it->first,make_pair(it->second.first,(it->second.second-desconto.preco))));

}

void procurar()
{
    system("cls");
    auto i=true;
    char opcao_procurar;

    cout<<"Nome do produto a ser procurado:";
    getline(cin,procura.nome);
    getline(cin,procura.nome);
    auto it=estoque.find(procura.nome);
    if(it==estoque.end())
    {
        cout pp <<"Produto não encontrado" p
    }else{
        cout pp <<"Produto:"<<it->first pp <<"Preço:"<<it->second.first pp <<"Quantidade em estoque:"<< it->second.second;
    }
    do{
    cout pp <<"Procurar outro produto[s/n]:";
    cin>>opcao_procurar;

    switch(opcao_procurar)
    {
        case 'N':
        case 'n':i=false;break;
        case 's':
            case 'S':i=false;procurar();break;

            default:cout pp <<"Eu fui bem claro idiota, é s de sim ou n de não!!" p
    }

    }while(i);


}

void excluir()
{
        system("cls");
        auto i=true;
        char opcao_excluir;
        cout<<"Entre com o produto a ser excluido:";
        getline(cin,exclui.nome);
        getline(cin,exclui.nome);
        estoque.erase(exclui.nome);
        auto it=estoque.find(exclui.nome);
        if(it==estoque.end())
        {
            cout<<"Produto excluido"p
        }else{
         cout<<"Produto não excluido" p
        }

       do{
    cout pp <<"Procurar outro produto[s/n]:";
    cin>>opcao_excluir;

    switch(opcao_excluir)
    {
        case 'N':
        case 'n':i=false;break;
        case 's':
            case 'S':i=false;excluir();break;

            default:cout pp <<"Eu fui bem claro idiota, é s de sim ou n de não!!" p
    }

    }while(i);

}

void cadastrar()
{
    char opcao_cadastro;
    system("cls");
    cout<<"Nome do produto:";
    getline(cin,cadastro.nome);
    getline(cin,cadastro.nome);
    cout pp<<"Preço:";
    cin>>cadastro.preco;
    cout pp<<"Quantidade:";
    cin>>cadastro.quantidade;
    auto x=true;
    estoque.insert(pair<string,pair<double,int>>(cadastro.nome,make_pair(cadastro.preco,cadastro.quantidade)));
    map<string,pair<double,int>>::iterator it;
    it=estoque.find(cadastro.nome);
    if(it==estoque.end())
    {
        cout pp <<"Produto não cadastrado" p
    }else{
        cout pp <<"Produto cadastrado" p
    }
    while(x)
    {
    cout<<"Deseja fazer outro cadastro?[s/n]:";
    cin>>opcao_cadastro;
    switch(opcao_cadastro)
    {
        case 's':
        case 'S':x=false;cadastrar();break;
        case 'n':
        case 'N':x=false;break;
        default:cout<<"Não temos essa opção, tente navamente" p;break;
    }
    }

}

void mostrar()
{

    sp
    cout<<"Produtos em estoque:";
    sp

    for(auto it=estoque.begin();it!=estoque.end();it++)
    {
            cout pp <<"Produto: "<<it->first pp<<"Preço: "<<it->second.first pp <<"Quantidade: "<<it->second.second p

            linha
    }


        system("pause");
}



main()
{
    setlocale(LC_ALL,"portuguese");

    //inicialização só para ter alguma coisa já

    estoque.insert(pair<string,pair<double,int>>("Computador",make_pair(1200.00,25)));
    estoque.insert(pair<string,pair<double,int>>("Celular",make_pair(1500.00,50)));
    estoque.insert(pair<string,pair<double,int>>("Escrivaninha",make_pair(299.99,10)));
    estoque.insert(pair<string,pair<double,int>>("Capacete",make_pair(300.00,7)));
    estoque.insert(pair<string,pair<double,int>>("Ocúlos de sol",make_pair(149.99,43)));
    estoque.insert(pair<string,pair<double,int>>("Mochila",make_pair(75,15)));
    estoque.insert(pair<string,pair<double,int>>("Caneta",make_pair(3.00,230)));
    estoque.insert(pair<string,pair<double,int>>("Lápis",make_pair(2.00,300)));
    estoque.insert(pair<string,pair<double,int>>("Tapetes",make_pair(18,60)));

    int escolha_inicio;
    auto rodando=true;
    do{
    cout<<"Estoque:" pp p
    cout<<"1)Cadastrar produtos" pp <<"2)Excluir produtos" pp <<"3)Ver produtos" pp <<"4)Procurar produto" pp << "5)Cadastrar promoção" pp<<"6)Sair de Estoque" p
    cout<<"Sua escolha:";
    cin>>escolha_inicio;

    switch(escolha_inicio)
    {
        case 1:cadastrar();system("cls");break;
        case 2:excluir();system("cls");break;
        case 3:mostrar();system("cls");break;
        case 4:procurar();system("cls");break;
        case 5:cadastrar_desconto();system("cls");break;
        case 6:abort();break;
        default:cout pp<<"Não temos essa opção";system("cls");break;
    }
    }while(rodando);

	return 0;
}
