# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220122
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('8466e3a37930fdb1b77f8976bef6875f12cd57423d82afded9e30c6a15fd2361b6c50991f43c4a6d61d354d11a5f6da3344da72b1efc67fb7eda30a5242b1873'
            'SKIP'
            '579c776fce963558b079b79aed2e4d9404e01ff990f91d57a28b4584a06e8abb38659b68a1d465652ba112c4c1a74c1a5389c6f7f1c259a7401b80d490225b4b')
b2sums=('5a4d37442aa7319e8ea4b18a0b29ea8a69a4b235a938bd26e76e977da12c6d8f2cf1ce6bda2fff41b14f39750dadd6d60e58cf80cab82eaf9eb8f71e4b997a63'
        'SKIP'
        '716255ec10b1811b70e8c3012157e55c0cc01c80bf78ce89e321e313e7ee410f6c9a68afc3607e56c1181e940798265dd54ec3a2b7f5b748e5d930d48e476302')
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
