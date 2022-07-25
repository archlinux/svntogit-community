# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220722
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('b3bee9861ad9537055f00ebc7a1593697cb9f53167bd79fb612b9567a1d19edb7b770e5e68cee410bf2a146f3c48608e7a47254972f28ca0418d725b8d2088d3'
            'SKIP'
            '4624afb1e3a00bb61d3a3d307be81e04ab994a272d6ede00b1742e2d423226ed747419cf89c7e10f5714a47d6c91ad1a698eb46ca68248f10b4b214f575da8f3')
b2sums=('76d9edddac82b5077d6416cf629dc02d427c93a42907f84a467a45805efe99154eaa175755a4a4c9a9d86df480842daef7064b1d324671eeb6c08fdbab3e7b70'
        'SKIP'
        '864c0e55b1853fd0b2bca53f2976d3306e560b77c07c729dc45aa839951469caa11642eaba88998bbf24e9c35f9587f0f795701a0cf0719e202a0cf2e2476055')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd "$pkgbase-$pkgver"

  # remove citation warnings
  patch -p1 <"$srcdir"/0001-Remove-citation-things.patch

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
