# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220222
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('3a5bb880fb4c4e2fa9ccda95359da36e16af5cdfc26095471613b03b994bf6fa2a8370933cc3a570069f5cb733475948b66f3d93cd78dfe20df5f0278148ba1e'
            'SKIP'
            'd0841cb0654ce7797874f9118cb44a57f84274b33e0984af29a67fd498b3f90f2a17450130490051d3f2191b533854989a27919b91c1f9af8ec0d6ba1d34fc99')
b2sums=('55cc38cc93007be6c31a7a24df5fa2411aea07fe148caeb87de7756e6c8fcd47e47af72e90cd6d142469abdc653cd4de67e5994932f6db6bb123701cee72f88b'
        'SKIP'
        '41a5a1a002e618fa903046580ea9ba7902e174b901a3d0d590eba38615a064fcdba85272f308285e536a56ef60aa71e4e32d5ec697d99825fea1074fd39d0121')
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
