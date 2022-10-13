namespace Estoque.Dominio
{
    public class Produto : BaseAncestral
    {
        private int codigoCategoria;
        private int subCategoria;
        public int CodigoCategoria { get => codigoCategoria; set => codigoCategoria = value; }
        public int SubCategoria { get => subCategoria; set => subCategoria = value; }
        public Produto(int codigo, string descricao, bool situacao, int codigoCategoria, int subCategoria)
            : base(codigo, descricao, situacao)
        {
            this.CodigoCategoria = codigoCategoria;
            this.SubCategoria = subCategoria;
        }
    }
}