# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Eric Johnson <eric@coding-zone.com>

pkgname=words
pkgver=2.1
pkgrel=7
pkgdesc="A collection of International 'words' files for /usr/share/dict."
arch=('any')
url="https://ftp.gnu.org/gnu/aspell/dict/0index.html"
license=('GPL' 'GPL2' 'custom')
depends=()
makedepends=('glibc' 'aspell')
install=words.install
source=(https://ftp.gnu.org/gnu/aspell/dict/en/aspell6-en-2020.12.07-0.tar.bz2{,.sig}
        https://ftp.gnu.org/gnu/aspell/dict/ca/aspell6-ca-2.1.5-1.tar.bz2{,.sig}
        https://ftp.gnu.org/gnu/aspell/dict/fi/aspell6-fi-0.7-0.tar.bz2{,.sig}
        https://ftp.gnu.org/gnu/aspell/dict/fr/aspell-fr-0.50-3.tar.bz2
        https://ftp.gnu.org/gnu/aspell/dict/de-alt/aspell6-de-alt-2.1-1.tar.bz2{,.sig}
        https://ftp.gnu.org/gnu/aspell/dict/it/aspell6-it-2.2_20050523-0.tar.bz2{,.sig}
        https://ftp.gnu.org/gnu/aspell/dict/de/aspell-de-0.50-2.tar.bz2
        https://ftp.gnu.org/gnu/aspell/dict/es/aspell6-es-1.11-2.tar.bz2{,.sig})
md5sums=('5968764e9c3691c30e656a6df751249f'
         'SKIP'
         '153d26f724866909c6faf49eecefe8b3'
         'SKIP'
         '6d1032116982c0efab1af8fce83259c0'
         'SKIP'
         '53a2d05c4e8f7fabd3cefe24db977be7'
         '13245374b03088608d729fd15c58cd7a'
         'SKIP'
         'b1217299a0b67d1e121494d7ec18a88d'
         'SKIP'
         '204a9737ff0110fb8c7d284bd7200f7d'
         '8406336a89c64e47e96f4153d0af70c4'
         'SKIP')
sha256sums=('4c8f734a28a088b88bb6481fcf972d0b2c3dc8da944f7673283ce487eac49fb3'
            'SKIP'
            'ebdae47edf87357a4df137dd754737e6417452540cb1ed34b545ccfd66f165b9'
            'SKIP'
            'f8d7f07b4511e606eb56392ddaa76fd29918006331795e5942ad11b510d0a51d'
            'SKIP'
            'f9421047519d2af9a7a466e4336f6e6ea55206b356cd33c8bd18cb626bf2ce91'
            '36d13c6c743a6b1ff05fb1af79134e118e5a94db06ba40c076636f9d04158c73'
            'SKIP'
            '3b19dc709924783c8d87111aa9653dc6c000e845183778abee750215d83aaebd'
            'SKIP'
            'f1b6f23d694fc12da193de5d5d2232797e87aecf684d8aa5872d83176eeb84ba'
            'ad367fa1e7069c72eb7ae37e4d39c30a44d32a6aa73cedccbd0d06a69018afcc'
            'SKIP')
b2sums=('2e200dd1d6d4277a73fa73207119546638d548e40936b5d4744b0d0955b87862257a026e382d344cd4b396099b503367815adc697788362529d9170c3cca6e8b'
        'SKIP'
        'a7b26408eb583ca56967508f00d9c617e6e4bec364f6c807813d5f6485c549b9b62f02ea5464c32c3b3a84477d8fb6e768c11fda7d262b56ff0b24d57e19fde0'
        'SKIP'
        '89b5e385f618a1aabbe0b3e688bd21cad1d15ff9945f61048d72a8d59dbe7551c6314de16dc34249370432459483b7badeae606dc48380d345aa977136c0a4ab'
        'SKIP'
        '674199a56d676ab65c414741e669b099a0f08f2010f3981caf30daff6726e516586aa771190eebf83570093c28a8732761a9166f587a933860a037f1dd561e0e'
        '45428b341fd7d2cdf098d6d85956b8e41794ad7a725cd7f3c703bcdb9995c6c18f89e78f06ddc14b7c570b21eea4d72e944ba293b2272d8c5d5a2a5447427327'
        'SKIP'
        '52df29098963be1a3b82bfd40b2236b9be11a0d8b13e127352b518d43bfb998a5e1bf1f647a21ada28abf984e6babaaade75969aa3bb8526e1224e65ba7d4925'
        'SKIP'
        'e4561aef88bb0228f905107621d8e8ee85500b14b4744350fb1d5c549d5e69200e0e503ce0e9479af4ce96bd2ed5ec74385af7e0359cdd716e22663aa6c29328'
        'cc035b4f9c6b12c90b7112ad414ee3f28c00554179e9e88d79ceb06e14edbb891a3d2f7d2b3a70945651ceccecc4250e8e1f187cb75e1f6bdbe653e278a54140'
        'SKIP')

validpgpkeys=("78DEC3DB0AEA763951322BBF71C636695B147849"
              "31A768B0808E4BA619B48F81B6D9D0CC38B327D7")

build() {
    mkdir -p "$srcdir/$pkgname"
    cd "$srcdir/$pkgname"

    find "$srcdir" -name '*.cwl' -not -path "$srcdir/$pkgname/*" -exec cp -u '{}' './' \;
    preunzip *.cwl
    for wl in *.wl; do
        iconv --from-code=ISO-8859-1 --to-code=UTF-8 $wl | \
        cut -d '/' -f 1 | LC_ALL=C sort -df > $wl.utf8
    done
    rm *.wl

    mkdir -p copy
    while read cr; do
        ver=$(cut -d '-' -f 2 <<< "$cr")
        cp "$cr" "copy/copyright-$ver"
    done <<< "$(find "$srcdir" -name 'Copyright')"
    chmod 644 copy/*

    # locale specific sort for other languages?
    # sort specified from FS#47262
    cat en-common.wl.utf8 en_US* | sort -u | LC_ALL=C sort -df > us-merged
    cat en-common.wl.utf8 en_GB* | sort -u | LC_ALL=C sort -df > gb-merged
    cat de-only.wl.utf8   de_*   | sort -u | LC_ALL=C sort -df > de-merged
}

package() {
    cd "$srcdir/$pkgname"

    install -Dm644 us-merged "$pkgdir/usr/share/dict/american-english"
    install -Dm644 gb-merged "$pkgdir/usr/share/dict/british-english"
    ln -s american-english   "$pkgdir/usr/share/dict/usa"
    ln -s british-english    "$pkgdir/usr/share/dict/british"

    install -Dm644 ca-common.wl.utf8 "$pkgdir/usr/share/dict/catala"
    ln -s catala "$pkgdir/usr/share/dict/catalan"

    install -Dm644 de-merged       "$pkgdir/usr/share/dict/ngerman"
    install -Dm644 de-alt.wl.utf8  "$pkgdir/usr/share/dict/ogerman"
    ln -s ngerman "$pkgdir/usr/share/dict/german"

    install -Dm644 fr-40-only.wl.utf8 "$pkgdir/usr/share/dict/french"

    install -Dm644 es.wl.utf8 "$pkgdir/usr/share/dict/spanish"
    install -Dm644 fi.wl.utf8 "$pkgdir/usr/share/dict/finnish"
    install -Dm644 it.wl.utf8 "$pkgdir/usr/share/dict/italian"

    install -d "$pkgdir/usr/share/licenses/$pkgname/"
    cp copy/*  "$pkgdir/usr/share/licenses/$pkgname/"
}

