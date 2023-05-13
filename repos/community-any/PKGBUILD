# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20230422
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('1e084746d6b108805d3f5828913450d1ff70a38ecd6655db55da89c5179a686d9622b13ca471ccf44b2034abb4e5c22664810b6a8e5859e3c0ecf241fa56c9ed'
            'SKIP'
            '7c4c9e938aa0256b0c6f821d475e8248d77ee8238469a53fa71f525e915ad7f1414d068f69236e901095f0efe1dbf59d8b52f690dbf620b8df538c4582b30d0f')
b2sums=('d89c6634d5884b008c1701730f1f09a1ab74148ea221eee69ed314f0e1823e224325cfbd3a08fc8060b60fadb7dfc62e4fe17df65d7376795cc4fb88c2acf53f'
        'SKIP'
        '3f92531439342c2cc7f29599d2f66bc996e266ed9cce8fd4cd36ca5a8ac8f9b69ea796f8e7eb63a355bcecbc5482a81d1fcf73b99ffe4d461881d114188ff1cb')
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
