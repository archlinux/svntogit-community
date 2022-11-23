# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20221122
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('cdae4ec3a5aaf1ae6c0d9dc35bad930c2b34ad4f91209de80d55258f1945e2df345708000a2facef3b647b6e0d4c275c909faf073961ae0b80b89efa8831211f'
            'SKIP'
            '9d22fcefc6ac6430fc81b3ba1d866dabee36ee786060e6f0d69539053a14eeb8e6df0343c3b445e78d1b2b5dea6126e1bb034afd0f9f52b3a57dc101e294e8fa')
b2sums=('0bb85853f3dd84dc51a9382f7d7867352ce45fb8ce628e8c7f09a6cc14f469164f290bdb50efc609963478f4644bce36237a4bbec8568a8c23ba34a85670d6a1'
        'SKIP'
        'dc5ec26655e10f49714151dae671b7fea6907b3277a23c52cc45ea0af17ab992a827efd801ecc966b5809f01d1eb825941cf4f7cf38739a159abc67e73efb8ab')
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
