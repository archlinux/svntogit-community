# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220322
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('2e486ac131404672c0da6b9391717588e2df2b41b3914d433f25cf313017a2bcc554462213979318e334e1ea95a3887d55b0e7c5f5837f637c00e19562d52fd9'
            'SKIP'
            'c4dc8f67a312a60ef40803a6d2937bfe5aa5ece50957f9458c319ff074a1cfc04dd4beb9096d58f98cedab2669d5c5ce5cc322d4d5dfd52ecd7687b6ecfa58d8')
b2sums=('d641f8bf59aced5b5c4d009fdcbbd79db03ac1cea45a315d220d4f1204f7f9f6b5c3b996487627fb356ffd1ab7c12eef7f3b5accf352ed43f414b7f72282620c'
        'SKIP'
        'cfabcc3c604f49c3c9cef7ce0049596925c432f0e0c5d19268a1bdd70b3d4daee30e43da76a39098b50af83a3d41f298be5ebefbaab974e51abdfbd87cc2ccea')
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
