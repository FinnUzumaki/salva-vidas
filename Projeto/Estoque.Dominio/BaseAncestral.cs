namespace Estoque.Dominio
{
    public abstract class BaseAncestral
    {
            private int codigo;
            private string descricao;
            private bool situacao;
            public int Codigo{ get => codigo; set => codigo = value; }
            public string Descricao { get => descricao; set => descricao = value; }
            public bool Situacao { get => situacao; set => situacao = value;}
            public BaseAncestral(int codigo, string descricao, bool situacao)
            {
                this.Codigo = codigo;
                this.Descricao = descricao;
                this.Situacao = situacao;
            }
    }
}