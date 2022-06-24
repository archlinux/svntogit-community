# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20220622
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
  '0002-Fix-makefile.patch'
)
sha512sums=('d01d86cd2ac373534d147eee8aa666fe26e7207362ea9c036c3744125f72c936d15cf2059429636454f21c8e8c6b3a60c8d761ddfde97ba7388d2cd00495bfa4'
            'SKIP'
            '5c98641615a391a0e27a0a4091c8e9faa8689fa1fd7fd6c514ad571ee0e5f63219cc8df4e57c38ebd2d977d5fe13192190849c1c949039cc6433d30f673214cd'
            'b9fd9645a32376244ce075402783d404842445d3d510d7cffe743e07038d304443bc99a01da74ece20709e8c97c8751b1e097b2e5e8b362a23f851686b2c54df')
b2sums=('a0fdb1ab330360c28d85ea5608760a961e663a5401b900e6e8eee944250bf233ae1e3f66e6a2b9d54f0c32702127593dab787d29eda636bd457dcc5d4b046785'
        'SKIP'
        '6c6292c983be25992990f0d307c48f351de7a2fdb2a442ab196f2c6fce708b00e2ee784382acb3b14c755c9a9eb5ee3b5bb4faf3be6672e7d756fee740800902'
        '5a8fd71c7aec3de071acfd0765cca417a6f4db5ca10e04b7786a70e890ecf608c1b4214b4d8d09d7f9c2d7f83c1beb3c569e80a40986d3fa037dc15b2b58bd66')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd "$pkgbase-$pkgver"

  # remove citation warnings
  patch -p1 <"$srcdir"/0001-Remove-citation-things.patch

  # patch in DESTDIR support to makefile
  patch -p1 <"$srcdir"/0002-Fix-makefile.patch

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
