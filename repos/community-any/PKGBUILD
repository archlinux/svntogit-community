# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220422
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('b4179c5ad936ed01753d91d75a012d6985dd8fb24f1e0d06fa7806352bfc59aeeedd42b15fd31b8294d25671aa474f885362c887875e79b32b613bfe1f9a262e'
            'SKIP'
            '255f50448b791c53087f68b1650a2aab86b5f80efb13228ffa2903ab1b3465faf50a17be8e9a6eba6d6e46e83a11781c4c8480e14ec125d826fd1253cdae7ed0')
b2sums=('5630c58a15cc6ce0dac0346188afa9916b18545a9da91854f3cae604fc3c2ced33fd3a5f17a2967693a2e28cbddb198a3e63372125721a8dc67af80cbf03e940'
        'SKIP'
        '410317d7ea9146d373daeba8d27738ed21598bb50b0a6ecb78a8b31eed4ebf0d1c2baf2a6f2bada62fce7ec2840e507604f48d00820498330fdfedbb18874e7a')
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
