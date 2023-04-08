# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20230322
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('4100de413d855bfa38773bce137a289aebd20a5ca7a1806d7933a47e40e09eab9eda70719158f675f7dac49952017dc2df338e735f75682906ecec74ddec65d2'
            'SKIP'
            '1a2389954876fc670d95e86e588ca204e4e040d59288202d1f4143de57baab56a41b3604c267f9bc52826d74a1184dd1183780d4b8cec4b1d4f7d452bb83f205')
b2sums=('6aa932f77b58f0982d40eebe4863efc009b0317753898edbd3c3fc385b2e4a094444bcceb5384037f656ceb3bc27c9ba5e042ff09a7a885bb5ba479ce7051cc3'
        'SKIP'
        '9b775b284ddc6270667c2bc9d0f904839ed915a6c5d6b1dc1a2e93b40a56f60b831ada7e327682a8cd2f9cb421bff2b00f55e5204c682fdaaa0197ae7fb93fe8')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd "$pkgbase-$pkgver"

  # remove citation warnings
  patch -p1 -i "$srcdir/0001-Remove-citation-things.patch"

  # remove gnu branding
  sed \
    --in-place \
    --regexp-extended \
    --expression 's/GNU\s{1,3}Parallel/Parallel/g' \
    --expression 's/run_gnu_parallel/run_parallel/g' \
    --expression 's/with_GNU_Parallel/with_Parallel/g' \
    --expression 's/GNU \$Global::progname/\$Global::progname/g' \
    --expression 's/@GNU_Parallel/@Parallel/g' \
    src/parallel
}

build() {
  cd "$pkgbase-$pkgver"

  ./configure --prefix=/usr

  make
}

package_parallel() {
  depends=('perl' 'procps')
  optdepends=('parallel-docs: documentation')

  cd "$pkgbase-$pkgver"

  make DESTDIR="$pkgdir" install

  # split documentation out of main package
  mv "$pkgdir/usr/share/doc" docs
}

package_parallel-docs() {
  pkgdesc+=' (documentation)'

  cd "$pkgbase-$pkgver"

  install -vd "$pkgdir/usr/share/doc"
  mv -v docs/* "$pkgdir/usr/share/doc"
}

# vim:set ts=2 sw=2 et:
