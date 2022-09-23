# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220922
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('8a1b8b0e3cd5548ceb32b3dd160303e5efd2ed3c4bce09abc09e17437c17b3688324a6b257893e838fb19ca0d55d08288ce2898098346dd78298ffb04a3c9536'
            'SKIP'
            '44f006c67318dc5a33b4737c6d541b989cbb0eedb9a84f0edc897456ccb4a42f8d6532e22c617347564d5ad902f491821b302a3ac4e7b9ea1632c6d1c596494c')
b2sums=('5cdb9daef3731a0de9a845f9686d506abe378973992953feec0b3502498adb0b20ed6ed13795748180555fc3557127dbb5b847030432d7b0039ea2f56818cea4'
        'SKIP'
        '876db20598bd641a30b51f2b4dc64d0e1f58e90521a9b5dca96ec81b09504ad7761c1674087d549ccfd70d9410a3343b4aa0aae5ace0ff7ff515ebf4f50756aa')
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
